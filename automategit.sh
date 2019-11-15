#!/bin/bash
git pull
make fclean
find . \( -name a.out \) -print -delete
find . \( -name *.sw* \) -print -delete
find . \( -name .DS_Store \) -print -delete
echo "\033[1;32mFiles/Flag:\033[0m"
read ADD
git add $ADD
echo "\033[1;32mCommit message:\033[0m"
read MSG
git commit -m "$MSG"
echo "\033[1;32mBransh\033[0m"
read BRANSH
git push $BRANSH
