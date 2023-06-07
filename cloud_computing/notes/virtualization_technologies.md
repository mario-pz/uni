# Virtualisation
The process of creating a virtual version of something, such as a computer system or network, using software. This allows multiple virtual instances to run on the same physical hardware, increasing efficiency and flexibility in managing resources.

# Para-virtualisation
In this case the Hardware environment is not fully simulated.
Hosted software still runs in its own isolated environment, however, as if it were running on a separate system. Hosted software must be properly converted in order to run
in such an environment. Critical instructions are implemented through appropriate hyper-calls for control transfer.

# HYPERVISORS
Hypervisors, also known as virtual machine monitors (VMMs), play a crucial role in enabling the creation and management of virtual machines (VMs) on physical hardware. Acting as a system middleware, hypervisors provide a layer of abstraction between the underlying hardware and the virtualized environments.

## Layer 1 Hypervisor
A Layer 1 Hypervisor, also known as a Bare-Metal Hypervisor, is directly installed on the physical hardware without the need for an underlying operating system. It has direct access to the hardware resources and manages the virtual machines directly. Layer 1 hypervisors are designed for high performance and efficiency as they eliminate the overhead of an additional operating system layer.

## Layer 2 Hypervisor
A Layer 2 Hypervisor, also known as a Hosted Hypervisor, is installed on top of an existing operating system. It relies on the host operating system for managing hardware resources and provides virtualization capabilities to guest operating systems. Layer 2 hypervisors are more flexible and can run on a wider range of hardware, but they may introduce additional overhead due to the underlying host operating system.

# Space Sharing
Space sharing is a fundamental concept in virtualization that allows multiple VMs to coexist on a single physical machine. With the help of hypervisors, the available system resources such as CPU, memory, and storage can be efficiently divided and allocated to different VMs, ensuring optimal utilization and preventing resource conflicts.

# Time Sharing
Time sharing, another key aspect facilitated by hypervisors, allows multiple VMs to share the computing resources in a time-sliced manner. The hypervisor dynamically switches between different VMs, providing each VM with a fair and predetermined amount of time to execute its tasks. This enables efficient utilization of the underlying hardware, as multiple VMs can run concurrently without causing interference or contention.

# Virtual Cluster
A virtual cluster is a software-defined cluster created within a virtualized environment by combining multiple virtual machines or containers. It emulates the behavior of a physical cluster, allowing resources to be dynamically allocated, scaling up or down as needed. Virtual clusters offer flexibility, scalability, and increased reliability, making them popular in cloud computing environments.