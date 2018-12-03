package View;
import Controller.LocationSQL;
import Controller.RechercheSQL;
import Model.Film;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import Model.SessionBD;
import java.text.Format;
import java.text.SimpleDateFormat;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.ListView;
import org.hibernate.Session;

public class FilmSearch {
    private RechercheSQL rechercheur;
    private LocationSQL stock;
    private Film currentFilm;
    private Scene searchScreen;
    private TextField titre,anneeMin,anneeMax,paysProd,langue,genre,realisateurPre,realisateurFam,acteurPre,acteurFam;
    private Text title,titreLab,anneeLab,paysLab,langueLab,genreLab,realisateurLab,acteurLab,title2,title3;
    private Text titreLab2,titreDetail,anneeLab2,anneeDetail,paysLab2,paysDetail,langueLab2,langueDetail,errorLocation
            ,dureeLab,dureeDetail,genreLab2,genreDetail,realisateurLab2,realisateurDetail,acteurLab2,acteurDetail,resumeLab,resumeDetail;
    private ListView filmSelection;
    private VBox org1,org2,org3;
    private HBox org,orgAnnee,orgRealisateur,orgActeur;
    private Group root;
    private Button search,steal;
    private String sessionBD;
    
    public FilmSearch(Session session){
        rechercheur = new RechercheSQL(session);
        stock = new LocationSQL(session);
        
        title = new Text("Recherche de Film");
        title2 = new Text("Film");
        title3 =  new Text("Detail du film");
        titreLab = new Text("Titre du film");
        anneeLab = new Text("Annee de production (Min - Max)");
        paysLab =  new Text("Pays de tournage");
        langueLab = new Text("Langue");
        genreLab = new Text("Genre");
        realisateurLab = new Text("realisateur");
        acteurLab =  new Text("Acteurs");
        
        titreLab2 =  new Text("Film");
        titreDetail = new Text(" ");
        anneeLab2 = new Text("Annee de production");
        anneeDetail = new Text(" ");
        paysLab2 = new Text("Pays de production");
        paysDetail = new Text(" ");
        langueLab2 = new Text("Langue");
        langueDetail = new Text(" ");
        genreLab2 =  new Text("Genre");
        genreDetail = new Text(" ");
        realisateurLab2 = new Text("Realisateur");
        realisateurDetail = new Text(" ");
        acteurLab2 = new Text("Acteur");
        acteurDetail =  new Text(" ");
        dureeLab = new Text("Duree du film");
        dureeDetail = new Text(" ");
        resumeLab = new Text("Resume du film");
        resumeDetail = new Text(" ");
        errorLocation = new Text("Vous ne pouver plus louer ce film");
        
        titre = new TextField();
        anneeMin = new TextField();
        anneeMax = new TextField();
        paysProd = new TextField();
        langue = new TextField();
        genre = new TextField();
        realisateurPre = new TextField();
        realisateurFam = new TextField();
        acteurPre = new TextField();
        acteurFam = new TextField();
        
        filmSelection = new ListView();

        search = new Button("Rechercher");
        steal = new Button("'Louer'");
        

        orgAnnee =  new HBox();
        orgAnnee.getChildren().addAll(anneeMin,anneeMax);
        
        orgRealisateur = new HBox();
        orgRealisateur.getChildren().addAll(realisateurPre,realisateurFam);
        
        orgActeur = new HBox();
        orgActeur.getChildren().addAll(acteurPre,acteurFam);
        
        org1=new VBox();
        org1.getChildren().addAll(title,titreLab,titre,anneeLab,orgAnnee,paysLab,paysProd,langueLab,
                langue,genreLab,genre,realisateurLab,orgRealisateur,acteurLab,orgActeur,search);
        
        org2=new VBox();
        org2.getChildren().addAll(title2,filmSelection);
        
        org3=new VBox();
        org3.getChildren().addAll(title3,titreLab2,titreDetail,anneeLab2,anneeDetail,paysLab2,paysDetail,langueLab2,langueDetail,dureeLab,dureeDetail,
                genreLab2,genreDetail,realisateurLab2,realisateurDetail,acteurLab2,acteurDetail,resumeLab,resumeDetail,steal,errorLocation);
        
        org =  new HBox();
        org.getChildren().addAll(org1,org2,org3);

        setAction();
        setText();
        setPosition();

        root=new Group();
        root.getChildren().add(org);

        searchScreen = new Scene(root,1400,900);
    }
    
    public Scene getScene(){
        return searchScreen;
    }
    
    private void setDetail(){
        titreDetail.setText(currentFilm.getTitre());
        Format formatter = new SimpleDateFormat("yyyy-MM-dd");
        anneeDetail.setText(formatter.format(currentFilm.getDateparue()));
        dureeDetail.setText(currentFilm.getDureemin()+"min");
        langueDetail.setText(currentFilm.getLangueoriginale());
        resumeDetail.setText(currentFilm.getResume());
        paysDetail.setText(rechercheur.getInfoPays(currentFilm));
        genreDetail.setText(rechercheur.getInfoGenre(currentFilm));
        realisateurDetail.setText(rechercheur.getInfoRealisateur(currentFilm));
        acteurDetail.setText(rechercheur.getInfoActeurs(currentFilm));
        return;
    }
    
    private void setAction(){
        search.setOnAction(event -> {
            System.out.println("Test de recherche");
            ObservableList<String> items;
            items = FXCollections.observableArrayList(rechercheur.effectuerRecherche(titre.getText(), anneeMin.getText(), anneeMax.getText(), paysProd.getText(),
                    langue.getText(), genre.getText(), realisateurPre.getText(), realisateurFam.getText(), acteurPre.getText(), acteurFam.getText()));
            if(items.isEmpty()){
                filmSelection.setMouseTransparent( true );
                filmSelection.setFocusTraversable( false );
            }else{
                filmSelection.setMouseTransparent( false );
                filmSelection.setFocusTraversable( true );
            }
            filmSelection.setItems(items);
        });
        
        steal.setOnAction(event->{
            System.out.println("Test de location");
            if(stock.steal(currentFilm,sessionBD))
                errorLocation.setVisible(false);
            else
                errorLocation.setVisible(true);
        });
        
        filmSelection.setOnMouseClicked(event->{
            System.out.println("clicked on " + filmSelection.getSelectionModel().getSelectedItem());
            currentFilm = rechercheur.getInfo(filmSelection.getSelectionModel().getSelectedItem().toString());
            setDetail();
            
        });      
    }
    
    private void setText(){
        title.setScaleX(1.5); title.setScaleY(1.5);
        title2.setScaleX(1.5); title2.setScaleY(1.5);
        title3.setScaleX(1.5); title3.setScaleY(1.5);
        errorLocation.setVisible(false);
        
        titre.setPromptText("Entrez un titre");
        anneeMin.setPromptText("1971-01-01");
        anneeMax.setPromptText("2048-12-29");
        paysProd.setPromptText("Pas le Perou");
        genre.setPromptText("horreur");
        langue.setPromptText("latin");
        realisateurPre.setPromptText("The");
        realisateurFam.setPromptText("Batman");
        acteurPre.setPromptText("Chuck");
        acteurFam.setPromptText("Norris");
        

    }
    
    private void setPosition(){
        org1.setTranslateX(50);
        org1.setTranslateY(15);
        org.setSpacing(100);
        org1.setSpacing(20);
        org2.setSpacing(20);
        org3.setSpacing(20);
        filmSelection.setMouseTransparent( true );
        filmSelection.setFocusTraversable( false );
    }
    
    void setSessionBd(String session){
        sessionBD = session;
    }
}