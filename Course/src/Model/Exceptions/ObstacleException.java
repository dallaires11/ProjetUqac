package Model.Exceptions;

import Model.EpreuveException;

public class ObstacleException extends EpreuveException {
    @Override
    public String getMessage() {
        String errorMessage = "Le vehicule a percute un obstacle";
        return errorMessage;
    }
}
