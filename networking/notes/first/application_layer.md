
# Application Layer

## What it defines
- Types of messages that
are exchanged, eg, request, response

- Compose the message:
Which fields and how the fields are identified in the message

- Semantics of the message
- Importance of fields

- Rules for when and how processes send and respond to messages
open protocols:
- Defined in RFCs
- They enable interoperability
- eg, HTTP, SMTP

# Protocols

## DNS
- hierarchical naming system for [computer networks](https://en.wikipedia.org/wiki/%CE%94%CE%AF%CE%BA%CF%84%CF%85%CE%B1_%CF%85 %CF%80%CE%BF%CE%BB%CE%BF%CE%B3%CE%B9%CF%83%CF%84%CF%8E%CE%BD "Computer networks"), using the protocol [IP](https://en.wikipedia.org/wiki/Internet_Protocol "Internet Protocol"). This system can and does map hostnames to IPs.
- Allows host aliasing
- Allows mail server aliasing
- Can do Load Balancing so that multiple IPs correspond to one name
- What not to do in DNS Server
- It should not be centralized because there will be a single point of failure.
- There will be a lot of traffic
- A centralized database should also be put in place
- It will need management
- If there is a local DNS Server the DNS query will be sent to the local one.
- The local has a cache of recent matches
- At the same time it acts as a proxy forwarding messages to the hierarchy
* Matching can be done either iteratively or recursively.

## TLD
* Responsible for com, org, net, edu, aero, jobs, museums, and all country domains.
* Network Solutions maintains the servers for the .com TLD
* Educause maintains .edu

## P2P
- is a network that allows two or more computers to share their resources equally. This network uses the processing power, storage space and bandwidth of the nodes.

## FTP 20/21
- **communication protocol** for transferring files in computer networks and its full name is File Transfer Protocol. In practice it is usually used by internet users to upload files to their websites.
- HTTP 80
- Used by most websites to communicate with web browsers. It is also used for many other things, such as downloading files to your computer or mobile device. transfer data between two servers on the internet and even send messages from one mobile phone to another.

## SMTP
-  Uses TCP to send message from client to server on port 25
* Direct transfer: The sending server to the receiving server
* Three mission phases
* handshake (greeting)
* transfer of messages
* closure
* Command/response interaction (such as HTTP, FTP)
* commands: ASCII text
* response: status code and phrase
* Messages must be in 7-bit ASCI
  
## POP3,
- Post Office Protocol [RFC 1939] authorization, download
- Once downloaded, the mails are deleted from the queue, so we will not see them in another client

## IMAP
- Internet Mail Access Protocol [RFC 1730]: more features, including handling of messages stored on the server
- Keeps the status the same between different clients and allows managing messages with folders

# Application Architecture
## Client-Server Client - server
- The clients do not communicate with each other

## Peer-to-Peer peer users
* There is no always-on server
* Arbitrary end systems communicate directly
* Peers require services from other peers, provide service to other peers
* Scalability – new peers increase service capabilities as well as requirements
* Peers connect sporadically and change IP addresses
* Complex management

## TCP
* Reliable transmission
* Flow control: The sender will not work in the absence of the receiver
* Congestion control: The sender stops when the network is overloaded
* Does not provide: timing, minimum throughput guarantee, security
* connection-oriented: A client-server connection is established.

## UDP
* Unreliable data transfer
* Does not provide: reliability, flow control, congestion control, timing, throughput guarantee, security and call establishment

Neither provides encryption. TCP needs the SSL protocol to provide encryption to its connections. It additionally provides data integrity and authentication at endpoints. This protocol appears in the Application Layer.

### Why is UDP used?
Use the UDP protocol when data transmission is more important than data utilization. In real-time applications such as games.

# State vs Stateless
* Stateless: does not retain information about past requests
* Stateful protocols are complex!
* Connection history must be maintained
* If the server/client crashes, the current states they have
* maintain may not coincide

Example:
	HTTP is “stateless”

# Persistent HTTP vs Non Persistent

- Lasting
- The server leaves the connection open after sending the response
- Subsequent HTTP messages between the same client/server are sent
over the same open connection
- The client sends a request as soon as it wants a referenced object
- Response time is as much as one RTT for all
- Non-permanent
- Requires 2 RTTs for each object (1 for the connection, 1 for the request)
- OS overhead for each TCP connection
- Browsers often open parallel

# RTT
The time a small packet to travel by
client to server round trip.

# Cookies
## Where its used
* authentication
* shopping baskets
* recommendations
* user session retention (Web e-mail)
## Bad
* Cookies allow sites to learn a lot about us
* We usually provide the sites with names and e-mails

## How they maintain “status”:
* Protocol endpoints: maintain status to sender/receiver in multiple transactions
* cookies: http messages transfer the condition