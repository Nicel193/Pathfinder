make all > /dev/null 2>&1

zsh run_test.sh easy
zsh run_test.sh medium
zsh run_test.sh hardest

make uninstall > /dev/null 2>&1
