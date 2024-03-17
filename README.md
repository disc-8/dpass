<h1 align="center">
 <img alt="dpass" src="assets/logo.png">
</h1>
</p>

`dpass` is a password generator and "manager" that uses a plain text input, like an **username** and **website** to make an uncrackable[^1] password.

It doesn't behave like a traditional password manager that generates random passwords into an encrypted file, which when deleted/corrupted without backups, takes all your accounts with it.
Instead it generates a password from your input data, and secures it with a master password.

>**[tl;dr]:** It makes passwords in a reproducible way, so you can get your passwords without saving them.

# Features
* Zero data stored anywhere, so you can't lose your passwords
* Small, only 60kb binary
* Aside from standard *NIX headers, zero dependencies
* Pretty secure
# Usage
 ```
$ dpass user example.org
[dpass] Master Password:
[dpass] Master Hash: 175774203
ḁǐ|ӃÚỄCƛǒmŻıṄфӅạЩẲѯZĲƮMŸӘҘµpƍ¬ỹѐṎҷГрṻеâ¦ӟẌḈḣḭƱĊĿÅ]ŹƴṞƥѠḶĽOẅỹ
```

# Installation
>[!NOTE]
> To run `dpass` on Windows, install WSL2 by running `wsl --install` in Powershell, then in WSL continue from Linux instructions.
>
> Native Windows port coming Soon™

## Linux
Run these commands in a terminal:
```
git clone https://github.com/disc-8/dpass
cd dpass
bash compile
sudo bash install global
```
**Enjoy!**

## OS X
Theoretically Linux instructions should work. If they don't, make an issue.

---

### zpass?
it's gone, and no, this isn't a rebranding, this is a whole new program based off of it.

[^1]: theoretically it is crackable, but the Sun will explode before you get compromised.