# Modern Systemdesign with C++

## Additional Packages

```sh
sudo apt install -y cargo npm
```

## Neovim installation

```sh
curl -LO https://github.com/neovim/neovim/releases/latest/download/nvim-linux-x86_64.tar.gz
sudo rm -rf /opt/nvim-linux-x86_64
sudo tar -C /opt -xzf nvim-linux-x86_64.tar.gz
```

Add this to `~/.bashrc`:

```sh
export PATH="$PATH:/opt/nvim-linux-x86_64/bin"
```

## Nerd Font Installation

```sh
mkdir -p $HOME/.local/share/fonts
wget -P $HOME/.local/share/fonts https://github.com/ryanoasis/nerd-fonts/releases/latest/download/Hurmit.zip
cd $HOME/.local/share/fonts
unzip Hurmit.zip && rm Hurmit.zip
fc-cache -fv
```

## VM Setup 

Devices -> Insert Guest Additions CD Images

```sh
sudo sudo mount /dev/cdrom /mnt
cd /mnt
sudo ./VBoxLinuxAdditions.run 
```
