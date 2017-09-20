# Congiguring Tor Access Point

# Activate Wifi to free it fron Network Manager

sudo nmcli radio wifi off
sudo rfkill unblock wlan

# IP config
ip addr add 10.0.0.1/24 dev wlan0

# hostapd
sudo apt-get install hostapd
hostapd ./hostapd.conf

# dnsmasq

sudo apt-get install dnsmasq
dnsmasq -C ./dnsmasq.conf

# configure link between 2 interfaces

sudo sysctl -w net.ipv4.ip_forward=1
sudo iptables -P FORWARD ACCEPT
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE

# TOR config
sudo apt-get install tor
sudo service tor start

sudo iptables -t nat -A PREROUTING -i wlan0 -p tcp -j DNAT --to-destination 10.0.0.1:9040
sudo iptables -t nat -A PREROUTING -i wlan0 -p udp --dport 53 -j DNAT --to-destination 10.0.0.1:53
sudo iptables -t nat -D POSTROUTING -o eth0 -j MASQUERADE
