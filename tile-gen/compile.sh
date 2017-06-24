#!/bin/bash

iter=1

mkdir compiled/${1}

cat $1 | while read line
do
    echo $line | awk '
          BEGIN{
          printf("4 4\nstarting positions for each tile:\n")
          }
          {
          for(i=1;i<=16;++i){pos[$i]=i}; 
          for(i=0;i<16;++i){printf("%d\n", pos[i]-1)};
          } 
          END{
          printf("goal positions:\n");
          for(i=0;i<16;++i){printf("%d\n", i)};
          }
     ' > compiled/$1/${iter}_4x4.tile # Actually, they may be 5x5 tiles.
     iter=`expr $iter + 1`
done

exit 

    echo $line | awk '
          BEGIN{
          printf("5 5\nstarting positions for each tile:\n")
          }
          {
          for(i=1;i<=25;++i){pos[$i]=i}; 
          for(i=0;i<25;++i){printf("%d\n", pos[i]-1)};
          } 
          END{
          printf("goal positions:\n");
          for(i=0;i<25;++i){printf("%d\n", i)};
          }
     ' > compiled/$1/${iter}_4x4.tile # Actually, they may be 5x5 tiles.
