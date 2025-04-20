#!/bin/bash

#
# This file is part of Snake.
#
# Copyright (C) 2025 Malte Lunkeit
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
#

PROGRAM_NAME="snake"
PROGRAM_DIR="$HOME/.$PROGRAM_NAME"

MAKE_COMMAND="make all"
MAKE_TARGET="build/snake"

GH_USER="mlunkeit"
GH_REPO="SnakeInC"
GH_BRANCH="main"

DOWNLOAD_URL="https://github.com/$GH_USER/$GH_REPO/archive/refs/heads/$GH_BRANCH.tar.gz"

# Required text formats
TEXT_BLUE="\033[34m"
TEXT_RED="\033[31m"

TEXT_BRIGHT_GREEN="\033[92m"

STYLE_RESET="\033[0m"

# A list of files where to edit the PATH variable
FILES=("$HOME/.bashrc" "$HOME/.bash_profile" "$HOME/.profile" "$HOME/.zshrc" "$HOME/.zprofile" "$HOME/.config/fish/config.fish")

PATH_LINE="export PATH=\"$PROGRAM_DIR/bin:\$PATH\""

error()
{
  echo -e "$TEXT_RED$1"
  exit
}

display_step_header()
{
  echo ""
  echo -e " $TEXT_BLUE($1/$2) $3$STYLE_RESET"
  echo ""
}

echo -e "$TEXT_BLUE"

echo "           _             _        _ _        _"
echo "          | |           | |      (_) |      | |"
echo " _ __ ___ | |_   _ _ __ | | _____ _| |_   __| | _____   __"
echo "| '_ \` _ \| | | | | '_ \| |/ / _ \ | __| / _\` |/ _ \ \ / /"
echo "| | | | | | | |_| | | | |   <  __/ | |_ | (_| |  __/\ V /"
echo "|_| |_| |_|_|\__,_|_| |_|_|\_\___|_|\__(_)__,_|\___| \_/"

echo -e "$STYLE_RESET"

if [ ! -d "$PROGRAM_DIR" ]; then
  mkdir "$PROGRAM_DIR"
else
  error "Error: The $PROGRAM_DIR directory already exists."
fi

cd "$PROGRAM_DIR" || error "Failed to enter program directory"

display_step_header 1 4 "Downloading"

curl -L -o $PROGRAM_NAME.tar.gz $DOWNLOAD_URL
tar -xzf $PROGRAM_NAME.tar.gz

display_step_header 2 4 "Building"

cd "$GH_REPO-$GH_BRANCH" || error "Failed to enter repository directory"
eval "$MAKE_COMMAND"

display_step_header 3 4 "Installing"

mkdir "$PROGRAM_DIR/bin"
cp "$MAKE_TARGET" "$PROGRAM_DIR/bin"

echo "Adding to PATH..."
for rcfile in "${FILES[@]}"; do
  if [ -f "$rcfile" ] && ! grep -Fxq "$PATH_LINE" "$rcfile"; then
    echo "Adding to $rcfile"
    echo "# This line is required for $PROGRAM_NAME to work." >> "$rcfile"
    echo "$PATH_LINE" >> "$rcfile"
  fi
done

display_step_header 4 4 "Cleaning up"

cd .. || error "Failed to exit repository directory"
echo "Deleting installation files..."
rm -r "$GH_REPO-$GH_BRANCH"
rm $PROGRAM_NAME.tar.gz

echo ""
echo -e "$TEXT_BRIGHT_GREEN Done! Please restart your terminal to use $PROGRAM_NAME."