-- Options are automatically loaded before lazy.nvim startup
-- Default options that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/options.lua
-- Add any additional options here
local o = vim.o
o.cursorlineopt = "both"
o.termguicolors = true

local opt = vim.opt
opt.relativenumber = false
opt.scrolloff = 5
opt.rnu = true
opt.nu = true
opt.spell = true
opt.spelllang = { "en_us", "de_de" }
