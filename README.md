# pcm2array
pcm to c array

convert wav to pcm in c array



wav to pcm, you need install sox

```shell
sox demo.wav --bits 16 --encoding signed-integer -c1 -r 8000 -L demo.raw
```

pcm to c array ( 16 bits signed int little endian)

```shell
pcm2array demo.raw > demo.c
```
