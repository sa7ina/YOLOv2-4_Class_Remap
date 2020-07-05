cd yolo_txt
ls "$PWD/"*.txt | head -1000000 > txt_list.tx
mv txt_list.tx ../
cd ..
./yolo_class_remap
