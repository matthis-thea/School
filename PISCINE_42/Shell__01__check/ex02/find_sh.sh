#!/bin/sh
find . -path  "*.sh" | rev | cut -c4- | cut -f1 -d"/" | rev
