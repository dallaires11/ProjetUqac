package Model.Exceptions;

import Model.EpreuveException;

public class CollisionException extends EpreuveException {
    @Override
    public String getMessage() {
        String errorMessage = "2 véhicules se sont violament percutes";
        return errorMessage;
    }
}
