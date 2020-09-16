if test ! -f numbers 
then 
 echo 0 > numbers
fi 

if ln numbers numbers.lock
 then 
 for i in 'seq 1 1000';
 do 
  n='tail -1 numbers '
  expr  $n+1>>numbers 
 done 
 
 #Unlock
 rm numbers.lock
fi 

# the error may occur when you execute: `bash ex2.sh; bash ex2.sh &`.
# race condition may occur, when both scripts want to access the file and write to it -> this will make garbage/not correct results in file.
# to prevent this, we can use `ln` to check, whether file is occupied by another process or not.
# critical region is a shared variables/data structures/memory segments, concurrent access of which can lead to unexpected beahaviour.
