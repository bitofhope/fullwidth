# fullwidth

Turn ASCII alphabetical characters into CJK ｆｕｌｌｗｉｄｔｈ Unicode characters.

## Summary

Takes input from standard input or cmdline args, you can use

`echo '<string>' | fullwidth -`

or

`fullwidth <string>`

if you wish to use from terminal.

## Build

Change directory to the root of the project,

1. `make`
2. `sudo make prefix=/usr install`

Note: Your system may use prefix of /usr/local use your noggin

## Acknowledgements

Application trivially created by forking https://github.com/co60ca/bunnysay
and deleting half the code. Thanks to Brad Kennedy for creating the adorable
`bunnysay`.

## License

This application is licensed under GNU General Public License v3.0. Please see
the LICENSE file for details.

