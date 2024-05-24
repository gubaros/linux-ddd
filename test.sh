#!/bin/bash

# Simple test script for dummy_driver

echo "Loading module..."
sudo insmod dummy_driver.ko
if [ $? -ne 0 ]; then
    echo "Failed to load module!"
    exit 1
fi

echo "Module loaded successfully!"

echo "Removing module..."
sudo rmmod dummy_driver
if [ $? -ne 0 ]; then
    echo "Failed to remove module!"
    exit 1
fi

echo "Module removed successfully!"

