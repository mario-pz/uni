# Cloud Notes 

Cloud Computing: ένα μοντέλο που προσφέρει την από οπουδήποτε, εύκολη (καθολική), κατ’ απαίτηση δικτυακή πρόσβαση σε μία κοινή «δεξαμενή» διαμορφώσιμων υπολογιστικών πόρων που μπορούν να παρασχεθούν γρήγορα και να απενεργοποιηθούν με ελάχιστη προσπάθεια διαχείρισης ή αλληλεπίδραση με τους παρόχους των υπηρεσιών.

Virtualisation: The process of creating a virtual version of something, such as a computer system or network, using software. This allows multiple virtual instances to run on the same physical hardware, increasing efficiency and flexibility in managing resources.

Para-virtualisation: Σε αυτήν την περίπτωση δεν προσομοιώνεται πλήρως το περιβάλλον Υλικού. 
Τα φιλοξενούμενα λογισμικά εξακολουθούν να εκτελούνται ωστόσο σε δικό τους απομονωμένο περιβάλλον, σαν να εκτελούνται σε ξεχωριστό σύστημα. Το φιλοξενούμενο λογισμικό πρέπει να μετατραπεί κατάλληλα προκειμένου να μπορεί να τρέξει
σε τέτοιο περιβάλλον. Οι critical instructions υλοποιούνται μέσω κατάλληλων hyper-calls για μεταφορά ελέγχου.

HYPERVISORS: Το ενδιάμεσο υποβοηθητικό λογισμικό συστήματος  μέσω του οποίου επιτελείται η δημιουργία μίας ή περισσοτέρων VMs πάνω στην πραγματική μηχανή, είναι γνωστό με τον όρο.

MapReduce: Πρόκειται για ένα προγραμματιστικό  μοντέλο, κατάλληλο για μαζική επεξεργασία πολύ  μεγάλων όγκων δεδομένων σε φθηνούς κατανεμημένους  πόρους με αυξημένη ανοχή λαθών Αναπτύχθηκε από την Google η οποία το  χρησιμοποιεί εσωτερικά για υποστήριξη των μαζικά  μεγάλου όγκου επεξεργασιών που κάνει καθημερινά.
H χρήση του στον υπόλοιπο κόσμο έγινε δημοφιλής μέσω της πρώτης αντίστοιχης ελεύθερης υλοποίησής  του. Χρησιμοποιείται έντονα και από τους άλλους γνωστούς  μεγάλους στο χώρο του cloud computing και γενικότερα  του Internet 

MapReduce vs Spark:
Το MapReduce είναι ένα πλαίσιο επεξεργασίας παρτίδας που είναι βελτιστοποιημένο για την παράλληλη επεξεργασία μεγάλων όγκων δεδομένων, ενώ το Spark είναι ένα υπολογιστικό πλαίσιο στη μνήμη που έχει βελτιστοποιηθεί για επεξεργασία σε πραγματικό χρόνο και επαναληπτική επεξεργασία μεγάλων συνόλων δεδομένων.

Capacity planning basics steps:
Τα βασικά βήματα περιλαμβάνουν την ανάλυση ιστορικών δεδομένων, την ανάπτυξη μοντέλων πρόβλεψης για την πρόβλεψη της μελλοντικής ζήτησης, τον προσδιορισμό της απαιτούμενης ικανότητας για την κάλυψη αυτής της ζήτησης και τη βελτιστοποίηση της χρήσης των πόρων ελαχιστοποιώντας παράλληλα το κόστος.


Live Migration:
Είναι σημαντικό σε ένα κέντρο δεδομένων επειδή επιτρέπει την απρόσκοπτη κίνηση  VMs μεταξύ φυσικών διακομιστών, χωρίς να διακόπτονται οι υπηρεσίες ή να προκαλούνται διακοπές λειτουργίας, διασφαλίζοντας έτσι τη συνεχή διαθεσιμότητα εφαρμογών και υπηρεσιών στους τελικούς χρήστες. 
* Προσδιορίστε τις απαιτήσεις μετεγκατάστασης: Προσδιορίστε την εικονική μηχανή που πρέπει να μετεγκατασταθεί, τους φυσικούς κεντρικούς υπολογιστές προέλευσης και προορισμού και τη συνδεσιμότητα δικτύου μεταξύ τους.

* Επαλήθευση συμβατότητας: Βεβαιωθείτε ότι οι φυσικοί κεντρικοί υπολογιστές προέλευσης και προορισμού είναι συμβατοί με την εικονική μηχανή και ότι η εικονική μηχανή πληροί τις απαιτήσεις για ζωντανή μετεγκατάσταση.

* Προετοιμασία της εικονικής μηχανής: Αναστείλετε την εικονική μηχανή για λίγο για να βεβαιωθείτε ότι η κατάσταση της μνήμης της είναι συνεπής και, στη συνέχεια, μεταφέρετε τη μνήμη, την αποθήκευση και την κατάσταση δικτύου της εικονικής μηχανής στον κεντρικό υπολογιστή προορισμού.

* Ολοκληρώστε τη μετεγκατάσταση: Συνεχίστε την εικονική μηχανή στον κεντρικό υπολογιστή προορισμού και βεβαιωθείτε ότι λειτουργεί σωστά.

* Επαλήθευση της μετεγκατάστασης: Πραγματοποιήστε δοκιμές για να επαληθεύσετε ότι η εικονική μηχανή λειτουργεί σωστά στον νέο κεντρικό υπολογιστή και βεβαιωθείτε ότι έχει αποκατασταθεί η συνδεσιμότητα δικτύου.

## Πλεονεκτήματα VM 
*_Σε σύγκριση με bare metal_*

* Μεγιστοποίηση της χρησιμοποίησης των πόρων
* Άμεση παροχή πόρων 
* Πολύ Υψηλές δυνατότητες κλιμάκωσης 
* Δυνατότητα μετακίνησης VMs μεταξύ hosts
* Δυνατότητα εξισορρόπησης φόρτου μεταξύ των hosts
* Υψηλές δυνατότητες ασφάλειας / απομόνωσης λαθών 
* Αν πέσει ένας host είναι δυνατό να μην επηρεαστούν καθόλου οι χρήστες 
*  Server consolidation
    
### Μέροι που δεν πρέπει να χρησιμοποιηθεί VM
* Εφαρμογές με ιδιαίτερα υψηλές απαιτήσεις σε πόρους
* Έλεγχος/μετρήσεις απόδοσης Υλικού 
* Έλεγχος συμβατότητας Υλικού 
* Εφαρμογές με ειδικές απαιτήσεις Υλικού
* Εφαρμογές στις οποίες ο συγχρονισμός είναι κρίσιμος
* Προσοχή σε θέματα αδειών

## BΑΣΙΚΑ ΧΑΡΑΚΤΗΡΙΣΤΙΚΑ CLOUD

Πολυχρηστικότητα: 
Οι παρεχόμενες υπηρεσίες πρέπει να υποστηρίζουν διαφορετικές εφαρμογές για διαφορετικούς χρήστες, διάφανα και αποδοτικά.
Οι εφαρμογές μπορούν να διαμοιράζονται πόρους αλλά πρέπει να εκτελούνται απομονωμένα και ανεξάρτητα για κάθε χρήστη. Η ανάπτυξη μιας νέας εφαρμογής θα πρέπει να απαιτεί μικρή προσπάθεια.

Εύκολη πρόσβαση:
Οι παρεχόμενες υπηρεσίες και εφαρμογές πρέπει να είναι εύκολα προσβάσιμες απ’ όλους με συνηθισμένους μηχανισμούς και ικανοποιητική ταχύτητα.


Ευρεία Κλιμάκωση:
Εταιρείες και οργανισμοί θα μπορούσαν να διαθέτουν πιθανά έως εκατοντάδες ή και χιλιάδες υπολογιστικά συστήματα… 
Μέσω του cloud παρέχεται η δυνατότητα να ανέλθουν σε δεκάδες χιλιάδες κ.ο.κ. καθώς και η δυνατότητα να αυξηθεί μαζικά το bandwidth και ο αποθηκευτικός χώρος.


Ελαστικότητα:
Οι εφαρμογές πρέπει να είναι σε θέση να διαπραγματεύονται και να λαμβάνουν επιπλέον πόρους προκειμένου να καλύπτουν τις διαρκώς αυξανόμενες ανάγκες τους σε υπολογιστική ισχύ και αποθηκευτική δυνατότητα

Pay As You Go:
Οι χρήστες πληρώνουν μόνο για τους πόρους που χρησιμοποιούν και μόνο για όσο χρόνο τους χρειάζονται.

Αυτοκαθορισμός των πόρων:
Οι χρήστες προβλέπουν και ζητούν μόνοι τους τις ανάγκες που έχουν σε υπολογιστικούς πόρους


## Υπηρεσίες Νέφους

Infrastructure as a Service:
Προσφέρεται στον πελάτη η δυνατότητα χρήσης της υπολογιστικής υποδομής του παροχέα - συνήθως VM. 

Software as a Service:
Προσφέρεται στον πελάτη η δυνατότητα χρήσης ολοκληρωμένων εφαρμογών λογισμικού, μέσω μόνο ενός browser. Ο παροχέας είναι εδώ αυτός που διαχειρίζεται τόσο την απαιτούμενη υποστηρικτική υποδομή όσο και το σύνολο των εργαλείων λογισμικού που απαιτούνται για τη λειτουργία των διατιθέμενων εφαρμογών.

Platform as a Service:
Προσφέρεται στον πελάτη η δυνατότητα χρήσης μίας πλατφόρμας με εργαλεία ανάπτυξης ολοκληρωμένων εφαρμογών.

S+S:
Ο πελάτης τρέχει ένα λογισμικό τοπικά και χρησιμοποιεί από τον παροχέα πρόσθετες υπηρεσίες.

Storage as a Service:
προσφέρεται στον πελάτη η δυνατότητα χρήσης χώρου  για αποθήκευση δεδομένων σε διάφορες μορφές.

Unified Communication as a Service:: 
προσφέρεται στον πελάτη η διανομή ενοποιημένων υπηρεσιών επικοινωνίας πάνω από διαφορετικές πλατφόρμες.

Αλλα::
* Hardware as a Service
* Communication as a Service
* Function as a Service
* Serverless
* Anything as a Service


## Cloud Models

Private:
Xρησιμοποιούνται για να περιγράψουν προϊόντα και υπηρεσίες που έχουν σαν σκοπό να εξομοιώσουν το cloud computing στα ιδιωτικά δίκτυα
 
Hybrid:
Συνδιασμός του Public και Private.

Public:
Περιγράφει το cloud computing υπό μία γενική τάση, όπου οι πόροι παρέχονται δυναμικά, σε μια αυτό-εξυπηρετούμενη βάση πάνω από το διαδίκτυο, μέσω web εφαρμογών ή web υπηρεσιών, από έναν εξωτερικό τρίτο πάροχο που μοιράζει τους πόρους και χρεώνει σύμφωνα με την χρήση

Dedicated (Private):
Φιλοξενείται σε data center που ανήκει στον χρήστη και διαχειρίζεται από τα εσωτερικά τμήματα τεχνολογίας πληροφορικής.

Community (Private):
Bρίσκεται στις εγκαταστάσεις ενός τρίτου, ανήκει, διαχειρίζεται και λειτουργεί από έναν πωλητή, ο οποίος μπορεί να διαθέτει αντίστοιχες υπηρεσίες και σε άλλους πελάτες (community). Ο πωλητής περιορίζεται από τον πελάτη με συμφωνητικά για το επίπεδο των υπηρεσιών (SLAs) κλπ.

### Actors in Cloud Computing

[sidebar]
.**Panel**
|===
|Actor |Definition

|Cloud Consumer
|Person or organization that maintains a business relationship with, and uses service from, Cloud Providers.

|Cloud Provider
|Person, organization, or entity responsible for making a service available to Cloud Consumers.

|Cloud Auditor
|A party that can conduct independent assessment of cloud services, information system operations, performance, and security of the cloud implementation.

|Cloud Broker
|An entity that manages the use, performance, and delivery of cloud services, and negotiates relationships between Cloud Providers and Cloud Consumers.

|Cloud Carrier
|The intermediary that provides connectivity and transport of cloud services from Cloud Providers to Cloud Consumers.
|===


### Στο Cloud Computing απαιτούνται γενικότερα τα ακόλουθα:

Γρήγορη επεκτασιμότητα υπηρεσίες που ζητούνται από χρήστες πρέπει πάντα να ικανοποιούνται.
Διασφάλιση συμφωνημένης ποιότητας υπηρεσιών Αποδοτική Χρήση πόρων

### Scaling Up and Down
* H δυνατότητα προσαρμογής του όγκου των υπολογιστικών πόρων που διατίθενται σε έναν συγκεκριμένο φόρτο εργασίας ή εφαρμογή σε περιβάλλον υπολογιστικού νέφους.

* Η κλιμάκωση, γνωστή και ως κατακόρυφη κλιμάκωση, περιλαμβάνει την προσθήκη περισσότερων πόρων για να αυξήσει την υπολογιστική ισχύ. Αυτό μπορεί να περιλαμβάνει την προσθήκη περισσότερων CPU, RAM ή αποθηκευτικού χώρου σε μια υπάρχουσα παρουσία για τη διαχείριση της αυξημένης ζήτησης.

* Η μείωση, από την άλλη πλευρά, περιλαμβάνει την αφαίρεση πόρων από ένα στιγμιότυπο ή τον τερματισμό των περιπτώσεων εντελώς για τη μείωση του κόστους και τη βελτιστοποίηση της χρήσης των πόρων.

* Σε περιβάλλον cloud, η κλιμάκωση προς τα πάνω και προς τα κάτω μπορεί να εκτελεστεί αυτόματα βάσει προκαθορισμένων ενεργειών. Αυτό επιτρέπει στους οργανισμούς να βελτιστοποιούν τους πόρους τους στο cloud και να διασφαλίζουν ότι ο φόρτος εργασίας τους έχει την απαραίτητη υπολογιστική ισχύ για να χειριστεί τις διακυμάνσεις της ζήτησης, αποφεύγοντας παράλληλα περιττό κόστος που σχετίζεται με την υπερβολική παροχή πόρων.


## Cloudnomics Laws
Utility services cost less even though they cost more::
Although utilities cost more when they are used, they cost nothing when they are not. Consequently, customers save money by replacing fixed infrastructure with Clouds when workloads are spiky, specifically when the peak-to-average ratio is greater than the utility premium.

On-demand trumps forecasting::
Forecasting is often wrong, the ability to up and down scale to meet unpredictable demand spikes allows for revenue and cost optimalities.

The peak of the sum is never greater than the sum of the peaks::
Enterprises deploy capacity to handle their peak demands. Under this strategy, the total capacity deployed is the sum of these individual peaks. However, since clouds can reallocate resources across many enterprises with different peak periods, a cloud needs to deploy less capacity.

Aggregate demand is smoother than individual::
Aggregating demand from multiple customers tends to smooth out variation. Therefore, Clouds get higher utilization, enabling better economics.

Average unit costs are reduced::
They are reduced by distributing fixed costs over more units of output. Larger cloud providers can therefore achieve economies of scale.

Superiority in numbers::
Superiority in numbers is the most important factor in the result of a combat. Service providers have the scale to fight rogue attacks.

Space-time is a continuum::
Organizations derive competitive advantage from responding to changing business conditions faster than the competition. With Cloud scalability, for the same cost, a business can accelerate its information processing and decision-making.

Dispersion is the inverse square of latency::
Reduced latency is increasingly essential to modern applications. A Cloud Computing provider is able to provide more nodes, and hence reduced latency, than an enterprise would want to deploy.

Don’t put all your eggs in one basket::
The reliability of a system increases with the addition of redundant, geographically dispersed components such as data centers and storage arrays. Cloud Computing vendors have the scale and diversity to do so.

An object at rest tends to stay at rest::
A data center is a very large object. Private data centers tend to remain in locations for reasons such as being where the company was founded, or where they got a good deal on property or a lease. A Cloud service provider can locate greenfield sites optimally and without such limits of legacy logic.

