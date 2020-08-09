from netaddr import *
ip_str = input('enter ip address\n')
ip = IPAddress(ip_str)
if(ip >= IPAddress('0.0.0.0') and ip<= IPAddress('127.255.255.255')):
    c = 'A'
    print('class of given ip is',c)
    k = 1
elif(ip >=IPAddress('128.0.0.0') and ip<= IPAddress('191.255.255.255')):
    c = 'B'
    print('class of given ip is',c)
    k = 1
elif(ip>=IPAddress('192.0.0.0') and ip<=IPAddress('223.255.255.255')):
    c = 'C'
    print('class of given ip is',c)
    k = 1
else:
    k = 0
if(k==1):
    dis_subnet = int(input('enter no of subnets\n'))
    for i in range(8):
        if(2**i>=dis_subnet):
            app_subnet = 2**i
            ex_bits = i
            break
    if(c=='A'):
        com_ip = IPNetwork(ip_str+'/'+'8')
        sub_mask = 8 + i
        subnets = list(com_ip.subnet(sub_mask))
        temp = 0
        for it_ip in subnets:
            print('net_id = ',it_ip.network,' ','broad_id = ',it_ip.broadcast,' ','usable hosts = ',int(it_ip.broadcast) - int(it_ip.network) - 1,' ','host range = ',IPAddress(int(it_ip.network)+1),' to ',IPAddress(int(it_ip.broadcast)-1))
            temp = temp+1
            if(temp==dis_subnet):
                break
    elif(c=='B'):
        com_ip = IPNetwork(ip_str+'/'+'16')
        sub_mask = 16 + i
        subnets = list(com_ip.subnet(sub_mask))
        temp = 0
        for it_ip in subnets:
            print('net_id = ',it_ip.network,' ','broad_id = ',it_ip.broadcast,' ','usable hosts = ',int(it_ip.broadcast) - int(it_ip.network) - 1,' ','host range = ',IPAddress(int(it_ip.network)+1),' to ',IPAddress(int(it_ip.broadcast)-1))
            temp = temp + 1
            if(temp==dis_subnet):
                break
    elif(c=='C'):
        com_ip = IPNetwork(ip_str+'/'+'24')
        sub_mask = 24 + i 
        subnets = list(com_ip.subnet(sub_mask))
        temp = 0
        for it_ip in subnets:
            print('net_id = ',it_ip.network,' ','broad_id = ',it_ip.broadcast,' ','usable hosts = ',int(it_ip.broadcast) - int(it_ip.network) - 1,' ','host range = ',IPAddress(int(it_ip.network)+1),' to ',IPAddress(int(it_ip.broadcast)-1))
            temp = temp + 1
            if(temp==dis_subnet):
                break
else:
    print('IP address provided cannot be used for subnetting\n')
