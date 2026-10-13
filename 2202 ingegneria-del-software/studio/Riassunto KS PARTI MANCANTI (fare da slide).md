### 1. Design Pattern e Architettura
- **Abstract Factory (Pattern Creazionale):** È completamente assente negli appunti. Nelle slide è spiegato come il pattern che fornisce un'interfaccia per creare _famiglie_ di oggetti correlati senza specificare le classi concrete (es. famiglie di "Icon" e "Text" che cambiano in base alla lingua).
- **"Progettare per Preservare":** Manca la lezione di "meta-ragionamento" che raggruppa i pattern in base allo scopo di prevenire future modifiche (es. mascherare dipendenze hardware con Factory/Bridge o nascondere gli algoritmi con Strategy/Visitor).

### 2. Tecniche di Refactoring
Negli appunti hai "Estrai Metodo", "Dividi Var Temp" e "Sostituisci Temp con Query". Mancano due tecniche fondamentali presenti sulle slide:
- **Sposta Metodo (Move Method):** Usata quando un metodo utilizza più caratteristiche di un'altra classe rispetto a quella in cui si trova, per ridurre l'accoppiamento.
- **Estrai Classe (Extract Class):** Usata per risolvere le classi "troppo grandi" (che violano il principio di singola responsabilità) separando attributi e metodi correlati in una nuova classe dedicata.

### 3. Strumenti di Sviluppo (Maven e JUnit 5)
L'intero ecosistema pratico dello sviluppo aziendale Java è assente negli appunti:
- **Apache Maven:** Manca l'automazione del build, la spiegazione della struttura delle directory convenzionali (`src/main/java` e `src/test/java`), il file di configurazione `pom.xml` e i comandi da terminale base (`mvn compile`, `mvn test`, `mvn package`).
- **JUnit 5 (Pratica):** Gli appunti parlano di test in via teorica, ma mancano le annotazioni reali usate in JUnit 5 (`@Test`, `@BeforeAll`, `@BeforeEach`). Manca anche la spiegazione dell'annotazione `@ParameterizedTest` (con `@CsvSource`) per eseguire lo stesso test con set di dati diversi.
### 4. Principi Fondamentali di Ingegneria del Software
Negli appunti mancano gli acronimi e i principi di base (best practices) della programmazione e del testing citati dal docente:
- **Principi Generali:** KISS (Keep It Simple, Stupid), DRY (Don't Repeat Yourself), YAGNI (You Ain't Gonna Need It) e LoD (Law of Demeter - non parlare con gli estranei).
- **Principi per il Testing (FIRST):** Fast, Isolated/Independent, Repeatable, Self-validating, Timely.
- **BDD (Behaviour-Driven Development):** Il pattern logico dei test basato su _Given_ (contesto), _When_ (evento) e _Then_ (risposta attesa).

### 5. Java Avanzato: Teoria e Sintassi
- **Meccanismo di Dispatch e Late Binding:** Gli appunti mostrano come usare il polimorfismo, ma non spiegano la differenza tecnica tra "tipo a compile-time" (variabile dichiarata) e "tipo a run-time" (istanza effettiva), e di come la JVM risolve quale metodo chiamare risalendo la gerarchia delle classi.
- **Java Record:** Usati negli esempi di codice degli appunti, ma manca la spiegazione formale: i record creano dati immutabili (campi `final`), generano getter automaticamente e non hanno setter, non potendo essere estesi.
- **Riferimenti a Metodi (Method Reference):** La spiegazione sintattica del passaggio logico dall'espressione lambda `(accum, v) -> accum + v` alla notazione `Integer::sum`.
- **Debug progressivo con `peek()`:** Manca l'esempio metodologico di usare `peek()` in mezzo alle pipeline degli Stream per stampare i risultati parziali dopo ogni operazione intermedia (`after map`, `after filter`, ecc.) senza consumare lo stream.

### 6. Testing Avanzato e Manutenzione
- **Criteri di Copertura del Codice (Code Coverage):** Gli appunti si fermano alla "Copertura del codice" e alla "Complessità Ciclomatica". Le slide invece pretendono la conoscenza della classificazione esatta: _copertura di funzioni, di costrutti (statement), di archi, di rami (branch) e di condizioni_.
- **Definizioni del Testing:** La slide separa rigorosamente le definizioni di Difetti di specifiche, di progettazione e di codice, e spiega cosa siano formalmente i Dati di test (test data), i Casi di test (test case) e la Test Suite.
- **Modelli di Manutenzione:** Le slide elencano specifici modelli applicativi per mantenere il software, ovvero il _Quick-fix_ (modifica rapida diretta al codice) e il _Miglioramento iterativo_ (analisi del sistema e refactoring), del tutto ignorati negli appunti.