#!/bin/bash

# Path to the .bashrc file
BASHRC="$HOME/.bashrc"

# Check if .bashrc exists
if [ -f "$BASHRC" ]; then
    echo ".bashrc file found. Adding environment variables..."

    # Append environment variable HELLO with the value of HOSTNAME
    echo 'export HELLO="$HOSTNAME"' >> "$BASHRC"

    # Append a local variable LOCAL with the output of whoami
    echo 'LOCAL="$(whoami)"' >> "$BASHRC"

    echo "Variables added to $BASHRC."

    # Open a new terminal (assuming GNOME Terminal; modify for other terminals)
    gnome-terminal &

else
    echo "Error: .bashrc file not found in the home directory."
fi

