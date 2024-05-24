#!/bin/bash

# Simple test script for dummy_driver

echo "Loading module..."
if sudo insmod dummy_driver.ko; then
    echo "Module loaded successfully!"
else
    echo "Failed to load module!"
    exit 1
fi

echo "Removing module..."
if sudo rmmod dummy_driver; then
    echo "Module removed successfully!"
else
    echo "Failed to remove module!"
    exit 1
fi
