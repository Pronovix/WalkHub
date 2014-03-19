#!/bin/bash
set +x

echo
echo "[Info] Bootstrap is cloning the repo"

INSTALL_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TMP_DIR="/tmp/walkhub"

rm -rf walkhub
rm -rf ${TMP_DIR}
git clone --recursive --branch walkhub https://github.com/marcelovani/xtemp.git ${TMP_DIR}

if [ -d ${TMP_DIR} ]; then
  echo "[Info] Bootstrap has finished installation."
  cd ${TMP_DIR}
  sh scripts/build.sh "${INSTALL_DIR}/walkhub"
else
  echo "[Error] Something went wrong when cloning the repo"
fi
