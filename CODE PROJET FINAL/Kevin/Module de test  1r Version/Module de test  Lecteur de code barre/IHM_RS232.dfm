object IHM_CodeBarre: TIHM_CodeBarre
  Left = 0
  Top = 0
  Caption = 'Application : Lecteur Code Barre'
  ClientHeight = 152
  ClientWidth = 309
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape_Etat: TShape
    Left = 142
    Top = 105
    Width = 25
    Height = 25
  end
  object Bouton_Deconnexion: TButton
    Left = 40
    Top = 105
    Width = 75
    Height = 25
    Caption = 'Deconnexion'
    TabOrder = 3
    OnClick = Bouton_DeconnexionClick
  end
  object GroupBox_Reception: TGroupBox
    Left = 24
    Top = 25
    Width = 258
    Height = 57
    TabOrder = 4
  end
  object Edit_Reception: TEdit
    Left = 142
    Top = 43
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Bouton_Reception: TButton
    Left = 40
    Top = 41
    Width = 75
    Height = 25
    Caption = 'Reception'
    TabOrder = 2
    OnClick = Bouton_ReceptionClick
  end
  object Bouton_Connexion: TButton
    Left = 40
    Top = 105
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 1
    OnClick = Bouton_ConnexionClick
  end
end
