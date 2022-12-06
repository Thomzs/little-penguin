cmd_/home/tmeyer/little-penguin/A07/main.mod := printf '%s\n'   main.o | awk '!x[$$0]++ { print("/home/tmeyer/little-penguin/A07/"$$0) }' > /home/tmeyer/little-penguin/A07/main.mod
