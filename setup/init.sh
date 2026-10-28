#!/usr/bin/env bash

SETUP_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
################################################################################
# INSTALL

PACKAGES="autoconf automake autotools-dev bc bison build-essential cmake curl ddd flex gawk git git-gui gitk gperf libboost-iostreams-dev libboost-log-dev libboost-program-options-dev libexpat1-dev libexpat-dev libglib2.0-dev libgmp-dev libgoogle-perftools-dev liblua5.3-dev libmpc-dev libmpfr-dev libtool libvncserver-dev ninja-build patchutils python3 python3-pip python3-pygame qtbase5-dev texinfo tree vim-gtk3 gedit xtightvncviewer zlib1g-dev gtkwave cargo npm tmux ripgrep fzf bc coreutils jq"
sudo apt install -y $PACKAGES

################################################################################
# SYSTEMC REPOSITORY

if [[ ! -d $HOME/Downloads/systemc ]]; then
  git clone https://github.com/accellera-official/systemc.git $HOME/Downloads/systemc
fi

cd $HOME/Downloads/systemc
git checkout 2.3.4
mkdir -p build
cd build
cmake -DCMAKE_CXX_STANDARD=14 -DCMAKE_INSTALL_PREFIX=/usr ..
make -j$(nproc)
make check -j$(nproc)
sudo make install

################################################################################
# DIFF-SO-FANCY

if ! command -v diff-so-fancy >/dev/null 2>&1; then
  LATEST_VERSION=$(curl -s https://api.github.com/repos/so-fancy/diff-so-fancy/releases/latest | grep -Po '"tag_name": "v\K[^"]*')
  sudo curl -L -o /usr/local/bin/diff-so-fancy "https://github.com/so-fancy/diff-so-fancy/releases/download/v${LATEST_VERSION}/diff-so-fancy"
  sudo chmod +x /usr/local/bin/diff-so-fancy
fi

################################################################################
# (UPDATE) NEOVIM
if ! command -v nvim >/dev/null 2>&1; then
  echo "Installing Neovim"
  cd "$HOME/Downloads/"
  curl -LO https://github.com/neovim/neovim/releases/latest/download/nvim-linux-x86_64.tar.gz
  sudo rm -rf /opt/nvim-linux-x86_64
  sudo tar -C /opt -xzf nvim-linux-x86_64.tar.gz
fi

################################################################################
# NERD FONT
FONTS="$HOME/.local/share/fonts"
if [[ ! -d "$FONTS/Hermit/" ]]; then
  echo "Installing Hermit Nerd Font"
  mkdir -p $FONTS
  wget -P $FONTS https://github.com/ryanoasis/nerd-fonts/releases/latest/download/Hermit.zip
  cd $FONTS
  unzip Hermit.zip && rm Hermit.zip
  fc-cache -fv
  cd
fi

################################################################################
# TPM - TMUX PACKAGE MANAGER
TPM_DIR="$HOME/.tmux/plugins/tpm"
if [[ ! -d $TPM_DIR ]]; then
  echo "Installing TPM"
  git clone https://github.com/tmux-plugins/tpm $TPM_DIR
fi

################################################################################
# ZOXIDE
if ! command -v zoxide >/dev/null 2>&1; then
  curl -sSfL https://raw.githubusercontent.com/ajeetdsouza/zoxide/main/install.sh | sh
fi

################################################################################
# SYMLINKS
BKP_DIR=$SETUP_DIR/bkp/

if [[ -d $BKP_DIR ]]; then
  echo "Removing Old Backup ..."
  rm -rf $BKP_DIR
fi

mkdir $BKP_DIR

brc="$HOME/.bashrc"
if [[ -f $brc ]]; then
  cp -L $brc $BKP_DIR
  rm -f $brc
fi

nvim_conf="$XDG_CONFIG_HOME/nvim"
if [[ -d $nvim_conf ]]; then
  cp -rL $nvim_conf $BKP_DIR
  rm -r $nvim_conf
fi
if [[ -f $nvim_conf ]]; then
  rm $nvim_conf
fi

tmux_conf="$XDG_CONFIG_HOME/tmux"
if [[ -d $tmux_conf ]]; then
  cp -rL $tmux_conf $BKP_DIR
  rm -r $tmux_conf
fi
if [[ -f $tmux_conf ]]; then
  rm $tmux_conf
fi

git_conf="$XDG_CONFIG_HOME/git"
if [[ -d $git_conf ]]; then
  cp -rL $git_conf $BKP_DIR
  rm -r $git_conf
fi
if [[ -f $git_conf ]]; then
  rm $git_conf
fi

ln -s $SETUP_DIR/.bashrc $HOME/.bashrc
ln -s $SETUP_DIR/config/nvim $XDG_CONFIG_HOME/nvim
ln -s $SETUP_DIR/config/tmux $XDG_CONFIG_HOME/tmux
ln -s $SETUP_DIR/config/git $XDG_CONFIG_HOME/git

################################################################################
# LOAD CONFIGS
source $HOME/.bashrc
cd
