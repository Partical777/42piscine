#!/bin/sh
ldapsearch -x -L "uid=z*" | grep "^cn" | cut -c5-999 | sort --reverse
