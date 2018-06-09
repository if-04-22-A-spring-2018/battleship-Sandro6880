/** @file mainpage.h
* @brief Description of battleship.
*/ 
/** @mainpage battleship -- Library to implement a game
*
* @author Peter Bauer
*
* This week you should implement parts of the old game called battleship. @ref english.
*
* Diese Woche sollen Sie kleine Teile eines beliebten Spiels implementieren. @ref german.
*
* @page english English Version
* @section intro Introduction
* In the game "battleship" two opponents maintain a field of (mostly) 10 times 10
* squares which are indicated either with "Water" or "Boat". In our simple version
* we are only using boats of one square's size. A boat must be surrounded by water.
* Each opponent has to place 15 boats.
*
* The player in turn is calling a position (row and column) where (s)he wants to shoot.
* His/her opponent has to tell, whether the shot hit water or a boat. Each player
* additionally maintains another field holding his/her guesses. First this field is
* covered with "Unknowns". Successively this fields get filled with either boat or
* water indicators.
*
* When hitting a boat the player can mark all surrounding cells with water, since a
* boat (see above) has to be surrounded by water.
*
* @section functions The Library's Interface
* - load_game() loads two files battleship.my and battleship.op holding the fields
* of the players.
*
* - get_shot() gets the shot of an opponent and indicates whether it hit a boat or
* only water.
*
* - shoot() shoots onto the opponent's field and marks the guessing field with the
* appropriate indicator.
*
* - get_my_guess() returns the value of a cell in the field holding the guesses.
*
* @section assignment Assignment
* Implement the library such that all unit tests given pass successfully.
*
* @page german Deutsche Version
* @section intro Einf&uuml;hrung
* Beim Spiel "Schifferlversenken" halten zwei SpielerInnen ein Spielfeld von (meist)
* 10 mal 10 Feldern, welche zu Beginn des Spiels entweder mit "Water" oder "Boat"
* gekennzeichnet werden. In unserer einfachen Spielversion werden wir nur Boote mit
* der Gr&ouml;&szlig;e 1 zulassen. Jedes Boot darf nur von Wasserzellen umgeben sein,
* d. h. Boote d&uuml;rfen nicht aneinandersto&szlig;en. JedeR SpielerIn muss 15
* Boote auf seinem/ihren Spielfeld platzieren.
*
* Der/die SpielerIn welche gerade an der Reihe ist, ruft eine Position (Zeile und
* Spalte), auf welche er/sie jetzt schie&szlig;en m&ouml;chte. Der/die GegenspielerIn
* gibt an, ob ein Boot oder nur Wasser getroffen wurde. Zus&auml;tzlich h&auml;lt
* jedeR SpielerIn ein Feld, in welchem die eigenen Versuche aufgezeichnet werden.
* Anfangs ist dieses Feld leer (alle Zellen sind Unknown). Im Spielverlauf wird
* dieses Feld mit Booten oder Wasser gef&uuml;llt.
*
* Wenn einE SpielerIn ein Boot trifft, darf es alle umliegenden Zellen mit Wasser
* markieren, da ja (siehe oben) jedes Boot von ausschlie&szlig;lich Wasser umgeben
* sein darf.
*
* @section functions_g Die Schnittstelle der Bibliothek
* - load_game() l&auml;dt zwei Dateien battleship.my und battleship.op, welche die
* Spielfelder der beiden SpielerInnen gespeichert haben.
*
* - get_shot() wird aufgerufen, wenn der/die GegnerIn schie&szlig;t und gibt an,
* ob Wasser oder ein Boot getroffen wurde.
*
* - shoot() wird aufgerufen, wenn auf das gegnerische Feld geschossen wird und setzt
* die Zellen des Feldes, welche die eigenen Versuche aufzeichnet, entsprechend.
*
* - get_my_guess() gibt den Wert der entsprechenden Zelle des Feldes mit den eigenen
* Versuchen zur&uuml;ck.
*
* @section assignment Assignment
* Implementieren Sie das Interface der Library so, dass die unit tests
* erfolgreich durchlaufen.
*
*/