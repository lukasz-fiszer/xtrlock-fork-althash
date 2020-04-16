# xtrlock fork allowing alternative hashes

This repo was forked from [debian xtrlock gitlab repo](https://salsa.debian.org/debian/xtrlock)

This modified version allows using alternative passwords/hashes to unlock the screen. It does not modify system passwords but keeps its own file with alternative hash if used. 

This was meant to be a quick modification useful for instance when frequently locking the screen for short periods of time. A shorter or simpler to type alternative password might be more practical and just faster in such situations.

This comes with its own security implications. In particular the alternative password should at least not be trivial and just faster to type. This was not intended to be a very secure modification but just a small practical tradeoff to be used adequately. Additionally, when unlocking a notification is send via `notify-send` with time elapsed since last locking the display.

#### Usage:

```
# clone this repo
git clone https://github.com/lukasz-fiszer/xtrlock-fork-althash.git
cd xtrlock-fork-althash
# build xtrlock
make xtrlock
sudo ./set-attributes.sh
# to use alternative hashes
make generate-althash
 ./generate-althash [passphrase]
# passphrase above is used as a parameter, might appear in cli history, prepend with space to prevent it in most cases
# use xtrlock with -h flag to allow alternative password hash
./xtrlock -h
```