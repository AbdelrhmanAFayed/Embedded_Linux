#!/bin/bash

USERNAME="test_user"
GROUPNAME="exp._group"

if getent group "$GROUPNAME" > /dev/null; then
    echo "Group '$GROUPNAME' already exists."
else
    echo "Group '$GROUPNAME' does not exist. Creating group..."
    groupadd "$GROUPNAME"
    echo "Group '$GROUPNAME' created successfully."
fi

if id "$USERNAME" > /dev/null 2>&1; then
    echo "User '$USERNAME' already exists."
else
    echo "User '$USERNAME' does not exist. Creating user..."
    useradd -m -g "$GROUPNAME" "$USERNAME"
    echo "User '$USERNAME' created successfully and added to group '$GROUPNAME'."
fi

echo "User Information:"
id "$USERNAME"

echo "Group Information:"
getent group "$GROUPNAME"

