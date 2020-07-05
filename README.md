# YOLOv2-4_Class_Remap
Remapping yolov2-4 *.txt annotations from to any class  

If you labeled a lot of files but want to add a class or change class order.  
If you labeled a bunch of images and noticed you chose the wrong class and don't want to start over.  
If you want to pseudo-lable from any yolo model and change all labels to your model needs.  
  
Now you can!  
  
How to use:  
1 - Just edit the remap_table.txt file. each line maps to one class like this:  
2 5  
3 0  
7 9  
12 3  
Every label with class 2 will changed to 5. 3 to 0. 7 to 9. and 12 to 3.  
  
2 - Copy all yolo annotation *.txt files to /yolo_class_remap/yolo_txt folder.  
  
3 - Run shell script: sh yolo_class_remap.sh  
  
4 - Copy and replace in your dataset folder all files created in /yolo_class_remap/yolo_txt/0_out folder.  
