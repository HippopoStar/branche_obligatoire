#!/bin/sh
find . -type f -name '*.sh' -print | rev | cut -d / -f1 | cut -b 4- | rev
