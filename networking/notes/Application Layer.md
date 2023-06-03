
# Application Layer
## Τι ορίζει
- Τύπους μηνυμάτων που 
ανταλλάσσονται, π.χ., request, response

- Σύνταξη του μηνύματος:
	Ποια πεδία και πώς τα πεδία προσδιορίζονται στο μήνυμα 

- Σημασιολογία του μηνύματος 
	- Σημασία των πεδίων
	
- Κανόνες για το πότε και πως οι διεργασίες στέλνουν και αποκρίνονται σε μηνύματα
open (ανοιχτά) protocols:
	- Ορίζονται στα RFCs
	- Επιτρέπουν τη διαλειτουργικότητα
		- π.χ., HTTP, SMΤP

### Διάφορα πρωτόκολλα
- DNS 
	- ιεραρχικό σύστημα ονοματοδοσίας για [δίκτυα υπολογιστών](https://el.wikipedia.org/wiki/%CE%94%CE%AF%CE%BA%CF%84%CF%85%CE%B1_%CF%85%CF%80%CE%BF%CE%BB%CE%BF%CE%B3%CE%B9%CF%83%CF%84%CF%8E%CE%BD "Δίκτυα υπολογιστών"), που χρησιμοποιούν το πρωτόκολλο [IP](https://el.wikipedia.org/wiki/Internet_Protocol "Internet Protocol"). Το σύστημα αυτό μπορεί και αντιστοιχίζει τα hostnames σε IP.
	- Επιτρέπει host aliasing
	- Επιτρέπει mail server aliasing
	- Μπορεί να κάνει Load Balancing ώστε πολλές IP να αντιστοιχούν σε ένα όνομα
	- Τι δεν πρέπει να κάνουμε σε DNS Server
		- Δεν πρέπει να κεντρικοποιηθεί γιατί θα υπάρχει μοναδικό σημείο αποτυχίας.
		- Θα υπάρξει μεγάλη κίνηση
		- Θα πρέπει να τοποθετηθεί επίσης μία κεντρικοποιημένη βάση δεδομένων
		- Θα χρειαστεί διαχείρηση

	  - Αν υπάρχει τοπικός DNS Server η ερώτηση DNS θα σταλθεί στον τοπικό.
		  - Ο τοπικός έχει cache πρόσφατων αντιστοιχήσεων
		  - Ταυτόχρονα λειτουργεί ως proxy προωθώντας μηνύματα στην ιεραρχία
		
	* Η εύρεση αντιστοιχίας μπορεί να γίνει είτε επαναληπτικά είτε αναδρομικά.

 * TLD 
	 * Υπεύθυνοι για com, org, net, edu, aero, jobs, museums, και όλα τα domains των χωρών.
	*  Η Network Solutions συντηρεί τους servers για το .com TLD
	* Educause συντηρεί το .edu
	
- P2P 
	- είναι ένα δίκτυο που επιτρέπει σε δύο ή περισσότερους υπολογιστές να μοιράζονται τους πόρους τους ισοδύναμα. Το δίκτυο αυτό χρησιμοποιεί την επεξεργαστική ισχύ, τον αποθηκευτικό χώρο και το εύρος ζώνης (bandwidth) των κόμβων.
	
- FTP 20/21
	- **πρωτόκολλο** επικοινωνίας για τη μεταφορά αρχείων σε δίκτυα υπολογιστών και η πλήρης ονομασία του είναι File Transfer Protocol. Στην πράξη χρησιμοποιείται συνήθως από τους χρήστες του διαδικτύου (internet) για να ανεβάσουν αρχεία στις ιστοσελίδες τους.
	
- HTTP 80
	-  Xρησιμοποιούν οι περισσότεροι ιστότοποι για να επικοινωνούν με προγράμματα περιήγησης ιστού. Χρησιμοποιείται επίσης για πολλά άλλα πράγματα, όπως τη λήψη αρχείων στον υπολογιστή ή την κινητή συσκευή σας. μεταφορά δεδομένων μεταξύ δύο διακομιστών στο διαδίκτυο, ακόμη και αποστολή μηνυμάτων από το ένα κινητό τηλέφωνο στο άλλο.
	
- SMTP
	-  Χρησιμοποιεί το TCP για να στείλει μήνυμα από τον client στο server στη θύρα 25
	* Άμεση μεταφορά: Ο αποστέλλων server στο λαμβάνοντα server
	* Τρεις φάσης αποστολής
		* handshaking (greeting)
		* transfer of messages
		* closure

	* Αλληλεπίδραση εντολών/αποκρίσεων (όπως HTTP, FTP)
		* commands: ASCII text
		* response: status code and phrase
		* Τα μηνύματα πρέπει να είναι σε 7-bit ASCI
  
- POP3, 
	- Post Office Protocol [RFC 1939] authorization, download 
	- Με το κατεβαστούν τα mail διαγράφονται από το queue οπότε δεν θα τα δούμε σε άλλο client

- IMAP
	- Internet Mail Access Protocol [RFC 1730]: περισσότερα χαρακτηριστικά, περιλαμβάνοντας διαχείριση μηνυμάτων που είναι αποθηκευμένα στο server
	- Κρατάει την κατάσταση ίδια μεταξύ διάφορων client και επιτρέπει διαχείρηση μηνυμάτων με φακέλους




## Αρχιτεκτονική Εφαρμογών
### Client-Server Πελάτη - εξυπηρέτης
	- Δεν επικοινωνούν οι clients μεταξύ τους
### Peer-to-Peer ομότιμοι χρήστες
* Δεν υπάρχει always-on server
* Αυθαίρετα end systems επικοινωνούν απευθείας

* Οι peers απαιτούν υπηρεσίες από άλλους peers, παρέχουν αντίστοιχα υπηρεσία σε άλλους peers

* Δυνατότητα επεκτασιμότητας – νέοι peers αυξάνουν τις δυνατότητες υπηρεσιών, αλλά και τις απαιτήσεις 

* Οι peers συνδέονται σποραδικά και αλλάζουν IP διευθύνσεις

* Πολύπλοκη διαχείριση

### TCP
* Αξιόπιστη μετάδοση
* Έλεγχος ροής: Ο αποστολέας δεν θα λειτουργήσει ερήμην του δέκτη
* Έλεγχος συμφόρησης: Ο αποστολέας σταματά όταν το δίκτυο υπερφορτωθεί
* Δεν παρέχει: χρονισμό, εγγύηση ελάχιστου throughput, ασφάλεια
* connection-oriented: Γίνεται εγκατάσταση σύνδεσης μεταξύ client-server.

### UDP
* Μη αξιόπιστη μεταφορά δεδομένων
* Δεν παρέχει: αξιοπιστία, έλεγχο ροής, έλεγχο συμφόρησης, χρονισμό, εγγύηση throughput, ασφάλεια και εγκατάσταση κλήσης

Κανένα από τα δύο παρέχει κρυπτογράφηση. Το TCP χρειάζεται το πρωτόκολλο SSL για να παράχει κρυγράφηση στις συνδέσεις του. Επιπρόσθετα παρέχει ακεραιότητα δεδομένων και αυθεντικοποίηση στα τερματικά σημεία. Το πρωτόκολλο αυτό εμφανίζεται στο Application Layer.


Q: Γιατί χρησιμοποιείται το UDP;
Το πρωτόκολλο UDP χρησιμοποιήτε όταν η μετάδοση των δεδομένων είναι πιό σημαντικό από την αξιοποίηση των δεδομένων. Σε εφαρμογές πραγματικού χρόνου όπως παιχνίδια.

### State vs Stateless
	 * Stateless: δεν διατηρεί πληροφορίες σχετικά με τα παρελθόντα αιτήματα 
	 * Τα πρωτόκολλα που διατηρούν την κατάσταση “state” είναι πολύπλοκα!
		 * Πρέπει να διατηρηθεί το ιστορικό των συνδέσεων
		 * Αν ο server/client καταρρεύσει, οι τρέχουσες καταστάσεις που έχουν
		 * διατηρήσει μπορεί να μη συμπίπτουν

	Παράδειγμα: 
		Το HTTP είναι “stateless”

### Διαρκές HTTP vs Μη Διαρκές
	- Διαρκές
		- Ο server αφήνει τη σύνδεση ανοιχτή αφού στείλει την απόκριση
		- Τα επόμενα HTTP μηνύματα  μεταξύ των ιδίων client/server στέλνονται
			πάνω από την ίδια ανοιχτή σύνδεση
		-  Ο client στέλνει ένα αίτημα μόλις θελήσει ένα referenced object
		-  Ο χρόνος απόκρισης είναι όσο ένα RTT για όλα τα 
	- Μη διαρκές
		- Απαιτεί 2 RTTs για κάθε αντικείμενο (1 για την σύνδεση, 1 για το request)
		- overhead του OS για κάθε TCP σύνδεση
		- Οι browsers συχνά ανοίγουν παράλληλες
			TCP συνδέσεις για να πάρουν τα referenced αντικείμενα

	RTT (ορισμός): Ο χρόνος ένα μικρό πακέτο να ταξιδέψει από τον
	client στο server μετ’ επιστροφής.


### Cookies
* αυθεντικοποίηση
* καλάθια αγορών
* συστάσεις
* διατήρηση συνεδρίας του χρήστη (Web e-mail)
* Κακά
	* Τα cookies επιτρέπουν στα sites να μάθουν πολλά για μας
	* Παρέχουμε συνήθως στα sites ονόματα και e-mail
	
Πώς διατηρούν την“κατάσταση”:
* Τερματικά σημεία των πρωτοκόλλων: διατηρούν 
κατάσταση στον αποστολέα/παραλήπτη σε 
πολλαπλές δοσοληψίες
* cookies: Τα http μηνύματα μεταφέρουν την 
κατάσταση