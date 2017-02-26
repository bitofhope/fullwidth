# bunnysay
Bunny Sign for terminals with UTF-8 support

```
｜￣￣￣￣￣￣￣￣￣￣｜
｜　ｂｕｎｎｙｓａｙ　｜
｜　　ｎｏｗ　ｗｉｔｈ｜
｜　　　ｆｉｘｅｄ　　｜
｜　　　ｗｉｄｔｈ　　｜
｜　　ｓｔｒｉｎｇ　　｜
｜＿＿＿＿＿＿＿＿＿＿｜
(\__/) ||
(•ㅅ•) ||
/ 　 づ
```

## Summary

Takes input from standard input or cmdline args, you can use

`echo '<string>' | bunnysay --`

or

`bunnysay <string>`

if you wish to use from terminal.

## Build
### Arch Linux
Available on the AUR as [bunnysay-git](https://aur.archlinux.org/packages/bunnysay-git)
### Other

Change directory to the root of the project,

1. `make`
2. `sudo make prefix=/usr install`

Note: Your system may use prefix of /usr/local use your noggin
