#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.ttmcore/ttmd.pid file instead
ttm_pid=$(<~/.ttmcore/testnet3/ttmd.pid)
sudo gdb -batch -ex "source debug.gdb" ttmd ${ttm_pid}
