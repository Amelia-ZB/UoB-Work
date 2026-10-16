# 00 - Intro

- exams in both exam periods


# 01 - Sysadmin

- ssh identity spoofing

- don't run everything as root

> [!CRITICAL]
> **root user is id 0**

## Permissions

ugo - user group other
RWX - read write execute

- can use octal to represent permissions
    - each character represents a category
    - the number represents the permissions

    - 777 = -rwxrwxrwx

- use chmod to change them

`chmod ⟨ugo⟩⟨±⟩⟨rwx⟩ ⟨file / folder⟩`

## Dirs

- to be able to cd in, you must set execute permissions

# 02 - Fundementals

## to learn

- sed
- shebang to compile & run a c program

## pipes

- \> write into

- \>> append to

- < get input from

- | from one command to the next

## Splices

- $( ... ) takes the command inside and replaces itself on the prompt with the output
- <() replaces the output with a temporary file contaning the output

## conditionals

test "${x}" -gt 3; then ...
[ "${x}" -gt 3 ]; then ...
[[ "${x}" -gt 3 ]]; then ...

test "${x}" -gt 3

if $?; then ...

[[ "${x}" -gt 3 ]] && ...

## variables

- x=5, sets x to the string "5"

## Functions

work like c
```
⟨identifier⟩() {
    ...
}
```

## scripting

using shellscript with a shebang `#!`

`#! /usr/bin/env bash`

`set -e` Exit on first error
`set -o pipefail` Exit if a command in a pipe fails

## Misc

- ending with & runs it in the background

- ctl+T can show what a program is doing (but rarely supported)

## boring list

awk :: useful tool for dealing with files
basename :: just the filename
bc :: maths stuff
cat :: join files
comm :: find common lines
cp :: copy files
crontab :: run commands at a time
cut :: extract fields from lines
dd :: bulk write to disks/tapes
df :: find free space
diff :: find differences
du :: how much space is this using
ed :: the standard text editor… (for use when you don’t have a screen)
env :: inspect environment variables
file :: what are you looking it?
finger :: what are other people doing
gz :: compress stuff
head :: get the top of a file
install :: like cp with permissions
kill :: kill a process
less/more :: view a long file
ln :: alias files and folder
man :: THE MANUAL
mkdir :: make a directory
mv :: rename stuff
patch :: automated changing of stuff
perl :: better (?) shellscript
ps :: what’s running?
read :: input
rm :: delete stuff
screen :: suspend terminal sessions and have multiple sessions in a single terminal (and connect to a serial console) (see also tmux)
sendmail :: send email ona commandline (you’llneed a mailserver though)
source :: read anotherfile
sed :: editing pipes
sort :: sorts
strings :: get things that look like text from a file
stty :: configure your terminal
tail :: get the bottom
tar :: archive stuff
tee :: write stuff to a file and look at it
trap :: signals
uniq :: remove duplicates
wait :: wait for backgrounded processes
wall :: terrible chat
wc :: count lines, words or characters
xargs :: helps avoid looping
yes :: helps avoid typing yes a lot (also these logic ops)
&& :: if command on left succeeds run command on right
|| :: if command on left fails run command on




# 03 - RegEx

grep: search
- -E extended RegEx
- -i case insensitive
- -o match strings instead of lines
- -v invert
- -R recursive (for folders)
- -c count matches instead of printing them


sed: replace
- -n dont print lines by default
- -E extended RegEx
- -i edit files in place

awk: general, for semi-structured data


"write only" code, you will forget how it works

- use just POSIX BRE (Basic RegEx)

## how to read

- left to right
    - if the char matches, keep going
    - otherwise go back

## syntax

- `.` any character
- `^` start of a line
- `$` end of a line
-
- `[]` any char in set
- `[^]` any char not in set
- `a-z A-Z 0-9 a-Z` shorthands for sets
- `:name:` named groups
- `\(\)` **group**: match whatever is inside it as a standalone thing
-
- `\?` match 0 or 1 times
- `\+` match 1 or more times
- `\*` match 0 or more times
-
- `\{n\}` match exactly n times
- `\{n,m\}` match between n and m times
- `\{n,\}` match n or more times
- `\{,n\}` match 0 to n times
-
- \n match whatever was matched in the nth group



# 04 & 05 - Git

- tracks progress & changes
- allows for rollbacks and collaboration
- lets you version each release easily & work out what was changed when
- lets you try things out without breaking the main version
- lets you make changes to previous versions easily
- lets you track each collaborators edits

## usage

- `git init .` init a repo
- `git add <file>` tell git to track a new file & stages changes
- `git commit` commit the change
    - `-m <message>` to supply a message
    - `-a` stage all changes
- `git log` show the changes log
- `git restore ⟨file⟩` revert changes to a file
- `git diff [commitID] [file]` show changes to a commit
- `git revert ⟨commitID⟩` revert an entire commit
- `git checkout ⟨commitID⟩` go back in time to a commit
- `git checkout main` go back to the current

## Branches

- `git branch` list name
- `git branch <name>` create branch
- `git switch <name>` change current branch
- `git merge <name>` bring edits from one branch to another

## conflicts

