# Modern Systemdesign with C++

```sh
git clone git@github.com:s-grundner/LVA-MSDCpp-KV.git $HOME/Documents
```

## Generate SSH Singing Keys

```sh
ssh-keygen -t ed25519 -C your.email@example.com
```

## Load Workspace Configuration and install dependencies

```sh
source $HOME/Documents/dotfiles/init.sh
```

- Neovim with Cpp Developer Tools
- Git Configuration
- tmux with [TPM](https://github.com/tmux-plugins/tpm)

To use TPM:

```sh
tpm source $XDG_CONFIG_HOME/tmux/tmux.conf
```

In the next tmux session, press `prefix+I` (capital `i` for install, prefix is Ctrl-B by default)
