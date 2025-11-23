
| **Operatore**           | **Sintassi**            | **Descrizione**                                                | **Esempio**                                         |
| ----------------------- | ----------------------- | -------------------------------------------------------------- | --------------------------------------------------- |
| **Selezione**           | `σ_cond(R)`             | Filtra le tuple che soddisfano una condizione.                 | `σ_{età > 30}(Impiegati)`                           |
| **Proiezione**          | `π_attr(R)`             | Seleziona solo alcuni attributi.                               | `π_{nome, età}(Impiegati)`                          |
| **Ridenominazione**     | `ρ_nome(R)`             | Rinomina relazione o attributi.                                | `ρ_{Imp}(Impiegati)`                                |
| **Unione**              | `R ∪ S`                 | Unisce tuple di due relazioni compatibili.                     | `Studenti ∪ Laureati`                               |
| **Intersezione**        | `R ∩ S`                 | Restituisce solo le tuple comuni a entrambe.                   | `Studenti ∩ Borsisti`                               |
| **Differenza**          | `R − S`                 | Restituisce le tuple in `R` ma non in `S`.                     | `Studenti − Fuoricorso`                             |
| **Prodotto cartesiano** | `R × S`                 | Combina ogni tupla di `R` con ogni tupla di `S`.               | `Impiegati × Dipartimenti`                          |
| **Join naturale**       | `R ⋈ S`                 | Join sulle colonne con lo stesso nome.                         | `Impiegati ⋈ Dipartimenti`                          |
| **Theta Join**          | `R ⋈_cond S`            | Join con condizione generica.                                  | `Impiegati ⋈_{Impiegati.idDip = D.id} Dipartimenti` |
| **Equijoin**            | `R ⋈_{A=B} S`           | Theta join con uguaglianza.                                    | `Impiegati ⋈_{idDip=id} Dipartimenti`               |
| **Divisione**           | `R ÷ S`                 | Restituisce i valori di `R` associati a _tutti_ quelli di `S`. | `Esami ÷ MaterieObbligatorie`                       |
