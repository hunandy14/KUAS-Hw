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
[\[���D\] C++Ū.raw�Ƕ�����](https://goo.gl/45nSe2)

## �Ƶ{�����}�C�ǻ�

### ���B�z�h�����гs�������D
�o�@�g�o�� [[���D] ���� ���Цs���r��](https://www.ptt.cc/bbs/C_and_CPP/M.1459748840.A.555.html)
�P���D���o�@�g�ѵ� [Re: [���D]���� ���Цs���r��](https://www.ptt.cc/bbs/C_and_CPP/M.1459819483.A.4D0.html)

�D�n���t���b��

�o�O������

```
    char **ptr;
    int n,m;
    char *temp;
    char *string1 = "BOOK";
    char *string2 = "FOR";
    char *string3 = "YOU";
    ptr = temp;
```

�s���覡���Ӭ�

```
    temp = string1;
    *ptr = temp;
    *(ptr + 1) = string2;
    *(ptr + 2) = string3;
```

### �Ƶ{�����ǻ�
���Ъ����жǻ��覡
[[���D] c�y���s����а��D!](https://www.ptt.cc/bbs/C_and_CPP/M.1463820406.A.81D.html)
[RE:[���D] c�y���s����а��D!](https://www.ptt.cc/bbs/C_and_CPP/M.1464282013.A.4D8.html)

���I�^��
> �� loveflames: int *a[row]�O���а}�C
> �� loveflames: int (*a)[row]�O���V�}�C������

�Ƶ{���ǥX�i�����S���D
�ǤJ�������n���W�x����ӬP�P�ǤJ
�_�h�N�n�ϥ� ���а}�C

1. ���а}�C => �Ыت��}�C�i�H�s����
2. ���Ъ����� => �Ψ��x�s����

���P���O2�O�����ʺA��(x,y)
1�h�O�u���b�ʺA�A�u���@�ӥi�ʺA
�ۤ񤧤U1���ЫشN���²��

## �L���r���W�X255�P0�L�k�Q�ѧO
�]���W�X255���᪽���q0�}�l��A�|���L�k�Q�ѧO���ǬO�W�X��
�B�z�覡����double�x�s�ƭȡA�bcast���L���r��