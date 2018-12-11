package Model.Exceptions;

import Model.EpreuveException;

public class PisteException extends EpreuveException {
    @Override
    public String getMessage() {
        String errorMessage = "Sortit de la piste, le véhicule est hors d'usage";
        return errorMessage;
    }
}
