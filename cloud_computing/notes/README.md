
# Cloud computing 
a model that offers anywhere, easy (universal), on-demand network access to a common "reservoir" of configurable computing resources that can be rapidly provisioned and decommissioned with minimal management effort or interaction with service providers.

# Requirements in Cloud Computing
Rapid scalability services requested by users must always be satisfied.
Ensuring agreed service quality Efficient use of resources.

# Capacity planning basics steps
Key steps include analyzing historical data, developing forecasting models to predict future demand, determining the required capacity to meet that demand, and optimizing resource utilization while minimizing costs.

# Scaling Up and Down
The ability to adjust the amount of computing resources available to a specific workload or application in a cloud computing environment.

Scaling, also known as vertical scaling, involves adding more resources to increase computing power. This may include adding more CPU, RAM, or storage to an existing instance to handle the increased demand.

Shrinking, on the other hand, involves removing resources from an instance or terminating instances altogether to reduce costs and optimize resource usage.

In a cloud environment, scaling up and down can be performed automatically based on predefined actions. This allows organizations to optimize their cloud resources and ensure that their workloads have the necessary computing power to handle fluctuations in demand, while avoiding unnecessary costs associated with over-provisioning resources.

# Live Migration
It is important in a data center because it allows VMs to move seamlessly between physical servers, without interrupting services or causing downtime, thus ensuring continuous availability of applications and services to end users.
- **Determine migration requirements**: Determine the virtual machine to be migrated, the source and destination physical hosts, and the network connectivity between them.

* **Verify compatibility: Verify that the physical source and destination hosts are compatible with the virtual machine and that the virtual machine meets the requirements for live migration.

* **Prepare the virtual machine**: Suspend the virtual machine for a while to ensure that its memory state is consistent, then transfer the memory, storage, and network state of the virtual machine to the destination host.

* **Complete the migration**: Continue the virtual machine on the target host and make sure it is working properly.

* **Verify the migration**: Perform tests to verify that the virtual machine is working correctly on the new host and ensure that network connectivity is restored.