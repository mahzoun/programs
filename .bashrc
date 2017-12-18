# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
export PS1='\[\033[01;32m\]\u@\H:\[\033[01;34m\]\w\$ \[\033[00m\]'
export HISTSIZE=10000000
export HISTFILESIZE=10000000
export GOPATH=~/go
export PATH=$PATH:/usr/local/go/bin
