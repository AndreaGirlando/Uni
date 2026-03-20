package unict;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

public class AppTest
{
    @ParameterizedTest
    @CsvSource({
        "1, 1, 2",
        "2, 3, 5",
        "10, 5, 15",
        "-1, 1, 0"
    })
    public void testAdd(int a, int b, int expected)
    {
        // Chiamiamo il metodo statico
        int risultato = App.add(a, b);

        // Verifichiamo il risultato: assertEquals(valore_atteso, valore_effettivo)
        assertEquals(expected, risultato);
    }
    @Test
    public void testMain(){
        App.main((null));
    }
}