#
# ~/.bashrc
#

_GREEN=$(tput setaf 2)
_BLUE=$(tput setaf 3)
_RESET=$(tput sgr0)
export PS1="${_GREEN}\u@MSD${_RESET}:${_BLUE}\w${_RESET}\$ "

################################################################################
#                                    PATH
################################################################################

. /opt/riscv-gnu-toolchain-multi-2026.08.07/env.sh

export PATH="$PATH:/opt/nvim-linux-x86_64/bin"
export PATH="$PATH:$HOME/.local/bin"
export PATH="$PATH:$HOME/ModernSystemDesign/riscv-tiny-rv32i/isa/build/lib"
eval "$(zoxide init bash)"
eval "$(fzf --bash)"

################################################################################
#                                   Aliases
################################################################################

alias ls='ls --color=auto'
alias la='ls -la'
alias grep='grep --color=auto'
alias matlab-term='matlab -nodesktop -nosplash'
alias cz="chezmoi"
alias n="nvim"

# Aliases: git
alias gs="git status --short"
alias gd="git diff --output-indicator-new=' ' --output-indicator-old=' '"
alias ga="git add"
alias gap="git add --patch"
alias gc="git commit"
alias gl="git log --all --graph --pretty=format:'%C(magenta)%h %C(white) %an %ar%C(auto)  %D%n%s%n'"
alias lg="lazygit"

################################################################################
#                                     GIT
################################################################################

export GIT_CONFIG_GLOBAL=$XDG_CONFIG_HOME/git/config

################################################################################
#                                     FZF
################################################################################

# Preview file content using bat (https://github.com/sharkdp/bat)
export FZF_CTRL_T_OPTS="
  --walker-skip .git,node_modules,target
  --preview 'bat -n --color=always {}'
  --bind 'ctrl-/:change-preview-window(down|hidden|)'"

# CTRL-Y to copy the command into clipboard using pbcopy
export FZF_CTRL_R_OPTS="
  --bind 'ctrl-y:execute-silent(echo -n {2..} | pbcopy)+abort'
  --color header:italic
  --header 'Press CTRL-Y to copy command into clipboard'"

# Print tree structure in the preview window
export FZF_ALT_C_OPTS="
  --walker-skip .git,node_modules,target
  --preview 'tree -C {}'"
