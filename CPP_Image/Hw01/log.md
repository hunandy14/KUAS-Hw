## ���D
macro���ഫ���G���۬Y�����Y  

```
if (((float)Ratio-(int)Ratio) > 0){
    black = 1/((float)Ratio-(int)Ratio);
    limx = Pic_x * ((float)Ratio-(int)Ratio);
    limy = Pic_y * ((float)Ratio-(int)Ratio);
}
```

�P  

```
if (float temp = ((float)Ratio-(int)Ratio) > 0){
    black = 1/temp;
    limx = Pic_x * temp;
    limy = Pic_y * temp;
}
```

�~�M�O���@�˪�  

> macro�p���ഫ��k������M�A
> ���p�O�p�Ʊ˱�覡���@��
> �Ϊ̬O�p��B�I�Ʈɷ|�����Ǥ���
> �`�N�H�ᤣ�i�H�� macro �p��D���
