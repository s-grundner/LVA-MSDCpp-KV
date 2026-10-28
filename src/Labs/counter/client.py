#!/usr/bin/env python3
# coding: utf-8

import sys
import socket
import fcntl, os
import errno
from time import sleep
import collections
import pygame


def setup_socket():
    port = 30000
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('127.0.0.1', port))
    return s


def read_socket_data(s):
    # see: http://stackoverflow.com/questions/16745409/what-does-pythons-socket-recv-return-for-non-blocking-sockets-if-no-data-is-r
    ans = None
    
    try:
        ans = s.recv(4096)
    except (socket.error, e):
        err = e.args[0]
        print(e)
        sys.exit(1)

    if len(ans) == 0:
        return None # remote socket end closed

    print("recv: {}".format(ans))
    return ans


digit_to_segments = {
    None: [1,1,1,1,1,1,1],
    0: [0,0,0,0,0,0,1],
    1: [1,0,0,1,1,1,1],
    2: [0,0,1,0,0,1,0],
    3: [0,0,0,0,1,1,0],
    4: [1,0,0,1,1,0,0],
    5: [0,1,0,0,1,0,0],
    6: [0,1,0,0,0,0,0],
    7: [0,0,0,1,1,1,1],
    8: [0,0,0,0,0,0,0],
    9: [0,0,0,0,1,0,0],
}


def decode_single_char(s):
    try:
        n = int(s)
    except ValueError:
        n = None
    return digit_to_segments[n]


def decode_socket_data(data):
    fields = data.split('#')
    if len(fields) < 2:
        print("WARNING: end of transmission delimiter missing -> display nothing")
        last = ''
    else:
        last = data.split('#')[-2]

    if len(last) > 6:
        print("WARNING: too many characters received -> truncating to six")
        last = last[-6:]
    last = last.rjust(6, '.')

    ans = [decode_single_char(e) for e in list(last)]
    return ans


BACKGROUND_COLOR = (0,0,0)
SEGMENT_FILL_COLOR = (255,0,0)
SEGMENT_BORDER_COLOR = (50,50,50)

BLOCK_WIDTH = 120
BLOCK_HEIGHT = 12
BORDER_MARGIN = 12
SEGMENT_MARGIN = 24

SEGMENT_WIDTH = 2*BLOCK_HEIGHT + BLOCK_WIDTH
SEGMENT_HEIGHT = 3*BLOCK_HEIGHT + 2*BLOCK_WIDTH
SCREEN_WIDTH = 6*SEGMENT_WIDTH + 2*SEGMENT_MARGIN + 2*BORDER_MARGIN + 3*BORDER_MARGIN
SCREEN_HEIGHT = SEGMENT_HEIGHT + 2*BORDER_MARGIN


def draw_counter(surface, active_segments, off=(0,0)):
    """
    draw a line - see http://www.pygame.org/docs/ref/draw.html
    
    pygame.draw.line(window, (255, 255, 255), (0, 0), (30, 50))
    """
    w = BLOCK_WIDTH
    h = BLOCK_HEIGHT
    b = BORDER_MARGIN

    def draw_segment(px,py,width,height,index):
        rect = (px+off[0],py+off[1],width,height)

        pygame.draw.rect(surface, SEGMENT_BORDER_COLOR, rect)
        
        if active_segments[index] == 0:
            surface.fill(SEGMENT_FILL_COLOR, rect)


    def v_draw(px, py, index):
        draw_segment(px, py, h, w, index)


    def h_draw(px, py, index):
        draw_segment(px, py, w, h, index)

    h_draw(b+h, b, 0)
    h_draw(b+h, b+h+w, 6)
    h_draw(b+h, b+2*h+2*w, 3)

    v_draw(b, b+h, 5)
    v_draw(b, b+2*h+w, 4)

    v_draw(b+h+w, b+h, 1)
    v_draw(b+h+w, b+2*h+w, 2)



sock = setup_socket()

pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

active_segments = decode_socket_data('......#')

shutdown = False
clock = pygame.time.Clock()
while not shutdown:
    for event in pygame.event.get(): 
        if event.type == pygame.QUIT: 
            sys.exit(0)

    screen.fill( BACKGROUND_COLOR )
    draw_counter(screen, active_segments[0], (0,0))
    draw_counter(screen, active_segments[1], (SEGMENT_WIDTH+BORDER_MARGIN,0))
    draw_counter(screen, active_segments[2], (2*SEGMENT_WIDTH+BORDER_MARGIN+SEGMENT_MARGIN,0))
    draw_counter(screen, active_segments[3], (3*SEGMENT_WIDTH+2*BORDER_MARGIN+SEGMENT_MARGIN,0))
    draw_counter(screen, active_segments[4], (4*SEGMENT_WIDTH+2*BORDER_MARGIN+2*SEGMENT_MARGIN,0))
    draw_counter(screen, active_segments[5], (5*SEGMENT_WIDTH+3*BORDER_MARGIN+2*SEGMENT_MARGIN,0))
    pygame.display.flip()

    if not shutdown:
        data = read_socket_data(sock)
        if data is None:
            print("Remote socket connection closed -> shuting down ...")
            shutdown = True
            sys.exit(0)
        else:
            data = data.decode("ascii")
            active_segments = decode_socket_data(data)
