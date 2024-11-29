#!/bin/bash

cd ~
mkdir myDirectory
mkdir secondDirectory
cd secondDirectory
touch myNotePaper
cp myNotePaper myDirectory
cd ~
cd myDirectory
mv myNotePaper myOldNotePaper 
