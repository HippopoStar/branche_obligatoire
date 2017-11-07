#!/bin/sh
ifconfig | grep "ether" | rev | cut -b 2- | cut -b -17 | rev
