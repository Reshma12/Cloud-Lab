Cloud-Lab
=========

cloud libvirt lab

# How to run xenlib.c

Steps :
    
    1. Run Xen Hypervisior
    2. Install libvirt package libvirt-dev(supports : QEMU, KVM, XEN, OpenVZ, LXC, and VirtualBox) :
    
          gcc apt-get install libvirt-dev
    
    3. Compile the code :
            
                gcc -g xenlib.c -o xen -lvirt
                (gcc -g program_name.c -o object_file -lvirt)
                
    

