#!/bin/bash
dir=$1
backupdir=$2
interval_secs=$3
max_backups=$4
starting_directory=$(pwd)
directory_info_last=directory_info_last.txt
if [ ! -f $directory_info_last ]
then
    touch $directory_info_last
fi
directory_info_new=directory_info_new.txt
if [ ! -f $directory_info_new ]
then
    touch $directory_info_new
fi
while(true)
do sleep  $interval_secs
ls -lR $dir > $directory_info_new
diff --brief <(sort $directory_info_last) <(sort $directory_info_new) >/dev/null
  if [[ $? -eq 1 ]]
  then
     file_name=`date +%Y-%m-%d-%H-%M-%S`
   mkdir $backupdir/$file_name
   cp -r $dir $backupdir/$file_name
   cp $directory_info_new $directory_info_last
   cd $backupdir
i=$(find . -mindepth 1 -maxdepth 1 -type d | wc -l)
while [[ $i -gt $max_backups ]];
do
   rm -vr `ls -c1 | tail -1`
   i=$i-1
done
  while [[ "$starting_directory" != "$(pwd)" ]]
   do
cd ..
done
fi
done
