# ���D
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

## macro
> macro��Ѽƥγ̦n���n�j���ӥH�W
> �p�G�|���ХΨ�A�Τ@���ܼƾɤJ

## fstream
fstream���O����Q�ƻs
[[���D] ���O���ƻs ��Ƹ̭���fstream ����](https://www.ptt.cc/bbs/C_and_CPP/M.1470845062.A.D86.html)

## �L���r��
�쥻�ϥ�char���x�s�Ϥ��A��ӵo�{�o�|�y�����D
����char���ƭȷ|�O�t�����A�����ϥ� `unsigned char`
�ϥΪ��ɭԳy�����֧x�Z�A��ӥN�X���վ�H��
`fstream` �u�Y `char` �ѼơA���大��o�{�i�H
����`cast`��L�h�N�n�F

`img.read((char*)&this->img_data[0], this->filesize);`

���o�˦b�̫e��[�J `(char*)` �̫ᦳ���\�ѨM