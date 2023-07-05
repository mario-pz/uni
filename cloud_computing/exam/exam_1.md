# Exam 1

# Explain what is IaaS, PaaS, SaaS along with providers/products that implement them

IaaS (Infrastructure as a Service): Provides virtualized computing resources like virtual machines, storage, and networking infrastructure. Examples include AWS EC2, Azure Virtual Machines, and GCP Compute Engine.

PaaS (Platform as a Service): Offers a platform for developing, deploying, and managing applications without worrying about infrastructure. Examples include Heroku and Google App Engine.

SaaS (Software as a Service): Provides ready-to-use software applications over the internet. Users access the software through a web browser or API. Examples include Salesforce, Microsoft Office 365, and Google Workspace.


# Explain the below laws of cloudnomics

## The Peak of the sum is never greater than the sum of peaks

When multiple entities share cloud resources, the combined peak demands are
usually lower than the sum of individual peak demands, leading to improved
resource allocation efficiency.


*(peak: highest resource usage)*

## Dispersion is the inverse square of latency

The latency experienced by users decreases with the square of the distance
between them and the data center. Cloud providers strategically locate data
centers to minimize latency and enhance application performance.

# Explain what is a hypervisor and its kinds and compare each other.

* Type 1 Hypervisor (Bare-Metal): Runs directly on hardware, offers better performance and security. Examples include VMware ESXi, Microsoft Hyper-V, and Xen. Used in server virtualization.

* Type 2 Hypervisor (Hosted): Runs as an application on top of an existing OS, provides flexibility and ease of use. Examples include VMware Workstation, Oracle VirtualBox, and Microsoft Virtual PC. Used in desktop virtualization.

Type 1 hypervisors have better performance and security but require dedicated hardware, while Type 2 hypervisors are more convenient for personal use and run on top of an existing OS.

# Explain OS-level virtualisation and its advantages/disadvantages on a basic level versus traditional techniques.

OS-level virtualisation, also known as containerization, is a virtualisation technique that allows multiple isolated user spaces, called containers, to run on a single host operating system (OS). Each container operates as a separate instance, providing a lightweight and efficient virtualisation solution. Containers share the same OS kernel and libraries, which enables efficient resource utilization and faster deployment times.

OS-level virtualisation offers advantages such as efficient resource utilization, lightweight and fast deployment and easy management and scalability compared to traditional virtualisation techniques.

The drawbacks of OS-level virtualisation are limited OS compatibilities because they share the kernel of the host. reduced isolation, any slight miss configuration can lead to getting the host hijacked and limited customization because containers are created opinionated in order to be portable and lightweight.


# Explain the basic steps to accomplish capacity planning

*(Capacity planning is the process of determining the resources and infrastructure required to meet current and future demands of an IT system)*

* Define objectives and requirements.
* Collect data on current performance and resource utilization.
* Analyze historical data for patterns and identify bottlenecks.
* Forecast future demands based on historical data and growth projections.
* Determine resource needs based on forecasted demands.
* Identify constraints and risks.
* Develop a capacity plan with recommended infrastructure changes.
* Implement changes and monitor performance.
* Regularly review and adjust the capacity plan based on feedback and changes.

# Explain what scaling up and scaling out means in a cloud computing system and in which scenario either is a better choice.

Scaling up, or vertical scaling, involves upgrading the hardware of a single resource to increase its capacity. It is suitable for scenarios with limited resource constraints, where a single powerful resource can efficiently handle the increased workload. Scaling up simplifies management as modifications are made to a single resource. On the other hand, scaling out, or horizontal scaling, involves adding more resources to distribute the workload. It is preferable when high availability, fault tolerance, or handling large workloads is essential. The choice between scaling up and scaling out depends on factors such as resource availability, cost, performance requirements, and the nature of the workload.

# Describe in short what is MapReduce and its basic characteristics

MapReduce is a programming model and framework developed by Google for processing and analyzing large-scale data sets in a distributed computing environment. It simplifies the parallel processing of big data by dividing tasks into two main phases: Map and Reduce.

In the Map phase, the input data is divided into smaller chunks, and each chunk is processed independently by mapping functions. These mapping functions transform the input data into key-value pairs, generating intermediate results.

In the Reduce phase, the intermediate results from the Map phase are collected and processed by reduce functions. The reduce functions aggregate and combine the intermediate results based on their corresponding keys, producing the final output.

# How does MapReduce handle (in a decentralized file system) cases of malfunctions

In a decentralized file system like HDFS, MapReduce ensures fault tolerance through mechanisms such as data replication, task redundancy, task monitoring and reexecution, node health monitoring, and job tracking and recovery. These mechanisms help handle malfunctions by replicating data, redistributing tasks, monitoring node health, and recovering from failures, ensuring uninterrupted data processing in a distributed environment.

# What is the basic difference between Spark and MapReduce, What is the difference between narrow and wide transformations  in Spark

Spark is a faster in-memory distributed computing framework that supports iterative algorithms and provides built-in libraries, while MapReduce is a disk-based batch processing framework that requires additional tools and libraries for advanced functionalities. In Spark, narrow transformations have a one-to-one mapping between input and output partitions, while wide transformations involve data shuffling across partitions.

# Explain for which basic reasons its very important to have as a support live migration in a data center. Explain the basic steps of live migration.

Live migration is important in data centers for resource optimization, high availability, load balancing, and energy efficiency. It allows running virtual machines (VMs) to be seamlessly moved between physical hosts without service interruptions. The basic steps of live migration include pre-migration checks, memory and disk state transfer, final synchronization, switching execution to the destination host, and post-migration verification.

# Given the below Fat Tree ( Portland )

## How does a pseudo-MAC gets used to find a location on the tree? Use as an example address 00:03:01:02:00:01.

* The device is connected to pod 00.
* It is connected to switch level 03 within the pod.
* It is connected to switch 01 within that level.
* The device is connected to port 02 on that switch.

## What type of Switch receives LDM packets from a root switch? Give a small description

In a Fat Tree network, the aggregation switch receives LDM (Leaf Discovery Message) packets from the root switch. Aggregation switches serve as intermediaries between the leaf switches and the core switches, aggregating and forwarding network traffic. They process the LDM packets to discover and gather information about the available leaf switches, updating routing tables for efficient communication within the network.
