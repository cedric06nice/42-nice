### BASE
Partitions
```sh
lsblk
```
Information sur le system
```sh
cat /etc/os-release
```
Installation des packages requis
```sh
apt-get install sudo ufw vim openssh-server libpam-pwquality apparmor cron
```

### SSH
Ouvrir et fermer les ports en editant le fichier `/etc/ssh/sshd_config`
```sh
Port 4242
PermitRootLogin no
```
Pour voir le status de SSH
```sh
systemctl status ssh
```

### UFW
Activer
```sh
ufw enable
```
Verifier le status
```sh
ufw status
```
Parametrer les rules par defaut
```sh
ufw default deny incoming
ufw default allow outgoing
```
Ajouter une nouvelle rule
```sh
ufw allow 4242
```
Effacer rule
```sh
ufw delete allow <port>
```

### PORT FORWARDING & CONNECTION EN SSH
Settings -> Network -> "Attached to NAT" -> Advanced -> Port Forwarding -> Ajouter le port 4242

Commande pour se connecter a distance au serveur:
```sh
ssh <user>@<ip address> -p <port>
```

### HOSTNAME
Voir le nom de l'hote
```sh
hostname
```
Pour le changer, editer les fichiers `/etc/hostname` et `/etc/hosts` puis reboot

### NOUVEL UTILISATEUR & GROUPES
Ajouter un nouvel utilisateur
```sh
sudo useradd <user>
```
Assigner un mot de passe a un utilisateur
```sh
sudo passwd <user>
```
Ajouter un utilisateur a un groupe
```sh
usermod -aG <group> <user>
```
Enlever un utilisateur d'un groupe
```sh
gpasswd -d <user> <group>
```
Effacer un utilisateur
```sh
deluser <user>
```

### PERMISSIONS SUDO & TTY
Apres avoir cree un nouvel utilisateur et l'avoir assigne au groupe `sudo`, ajouter une rule pour `sudo` dans le fichier `/etc/sudoers`
```sh
<user> ALL=(ALL:ALL) ALL
Defaults badpass_message="Your phrase"
Defaults passwd_tries=3
```
Se logger avec l'utilisateur `sudo`, creer le dossier `/var/log/sudo` qui contiendra le fichier `sudo.log`

Editer le fichier `/etc/sudoers`
```sh
Defaults logfile="/var/log/sudo/sudo.log"
Defaults iolog_dir="/var/log/sudo"
Defaults log_input,log_output
Defaults requiretty
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
```

### SCRIPT & CRON
Creer le fichier `monitoring.sh` et changer ses permissions en execution
```sh
chmod +x ./monitoring.sh
```
Ouvrir et editer le fichier `crontab -e` a partir de `root`
```sh
*/10 * * * * sh /usr/local/bin/monitoring.sh
```
* *Pendant l'evaluation, commenter la ligne pour arreter le cronjob*

### PASSWORD POLICY
Editer le fichier `/etc/login.defs`
```sh
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```
Editer le fichier `/etc/security/pwquality.conf`
```sh
difok = 7
minlen = 10
dcredit = -1
ucredit = -1
maxrepeat = 3
usercheck = 1
enforce_for_root
```
