Per creare i vari nodi clonare quella base. Per creare quella base basta fare setup-alpine.
![[Pasted image 20260527130323.png|700]]
###### Setup RETE1
**NODO 1**:  `ip addr add 192.168.1.10/24 dev eth0`
**NODO 2**:  `ip addr add 192.168.1.11/24 dev eth0`

**SWITCH**:
- *Aggiungiamo il bridge*
	- `ip link add br0 type bridge`
- *Aggiunta interfacce al bridge*
	- `ip link set eth0 master br0`
	- `ip link set eth1 master br0`
- *Attivazione modalità promiscua*
	- `ip link set eth0 promisc on`
	- `ip link set eth1 promisc on`
- *Attivazione delle interfacce*
	- `ip link set eth0 up`
	- `ip link set eth1 up`
	- `ip link set br0 up`

Per vedere se tutto è settato bene: `ip link show`
Da VirtualBox tocca creare 2 cavi dentro la tab rete dello switch e poi collegare i due nodi usando quest'ultimi

###### Aggiunta del router e setup RETE2
**SWITCH**:
- *Setuppiamo la terza interfaccia*
	- `ip link set eth2 up`
	- `ip link set eth2 promisc on`
	- `ip link set eth2 master br0`
**ROUTER**:
- *Setuppiamo l'interfaccia verso la RETE1*
	- `ip addr flush dev eth0`
	- `ip addr add 192.168.1.254/24 dev eth0`
	- `ip link set eth0 up`
- *Setuppiamo l'interfaccia verso la RETE2*
	- `ip addr flush dev eth1`
	- `ip addr add 192.168.2.254/24 dev eth1`
	- `ip link set eth1 up`
- *Abilitiamo il IP forwarding tra le porte del router*
	- `sysctl -w net.ipv4.ip_forward=1`

**NODO 3**: 
- `ip addr add 192.168.2.10/24 dev eth0`
- `ip link set eth0 up`
- `ip route add default via 192.168.2.254` (Dice al nodo: "Se non sai dove mandare un pacchetto, dallo al router")

**NODO 1**: `ip route add default via 192.168.1.254`
**NODO 2**: `ip route add default via 192.168.1.254`