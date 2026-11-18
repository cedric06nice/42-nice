# Born2beRoot

A hardened Debian server in a virtual machine, set up by hand: partitions, SSH on a custom port, a firewall, a strict `sudo` policy, a password policy and a monitoring script run by `cron`.

Part of my training at [42 Nice](https://42nice.fr). Score: 90/100.

These are the setup notes I wrote while building it, translated from French.

## Base system

```sh
lsblk                      # check the partition layout
cat /etc/os-release        # system information
apt-get install sudo ufw vim openssh-server libpam-pwquality apparmor cron
```

## SSH

In `/etc/ssh/sshd_config`: listen on port 4242 and forbid root login.

```sh
Port 4242
PermitRootLogin no
```

```sh
systemctl status ssh
```

## Firewall (UFW)

```sh
ufw enable
ufw default deny incoming
ufw default allow outgoing
ufw allow 4242
ufw status
ufw delete allow <port>    # remove a rule
```

## Port forwarding and remote login

VirtualBox: Settings → Network → "Attached to NAT" → Advanced → Port Forwarding → add port 4242.

```sh
ssh <user>@<ip address> -p 4242
```

## Hostname

```sh
hostname                   # show it
```

To change it, edit `/etc/hostname` and `/etc/hosts`, then reboot.

## Users and groups

```sh
sudo useradd <user>
sudo passwd <user>
usermod -aG <group> <user>     # add to a group
gpasswd -d <user> <group>      # remove from a group
deluser <user>
```

## sudo policy

After adding the user to the `sudo` group, add these rules to `/etc/sudoers`:

```sh
<user> ALL=(ALL:ALL) ALL
Defaults badpass_message="Your phrase"
Defaults passwd_tries=3
Defaults logfile="/var/log/sudo/sudo.log"
Defaults iolog_dir="/var/log/sudo"
Defaults log_input,log_output
Defaults requiretty
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

Create `/var/log/sudo/` first: it holds `sudo.log` and the input/output logs.

## Monitoring script and cron

`monitoring.sh` broadcasts the system's state (CPU, memory, disk, load, connections) to every terminal. Make it executable, then run it every 10 minutes from root's crontab (`crontab -e`):

```sh
chmod +x /usr/local/bin/monitoring.sh
*/10 * * * * sh /usr/local/bin/monitoring.sh
```

## Password policy

`/etc/login.defs`:

```sh
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

`/etc/security/pwquality.conf`:

```sh
difok = 7
minlen = 10
dcredit = -1
ucredit = -1
maxrepeat = 3
usercheck = 1
enforce_for_root
```

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
