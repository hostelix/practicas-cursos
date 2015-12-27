
var ButtonComponent = React.createClass({
  getInitialState: function() {
    return {};
  },

  getDefaultProps: function () {
    return {
      id: "idBu_default",
      valBtn: "Default",
      tipo: 'default'
    };
  },

  render: function(){
    return React.DOM.button({
      id: this.props.id,
      className: this.setTipoBtn(this.props.tipo) ,
      children: this.props.valBtn
    })
  },

  setTipoBtn: function(type){
    switch(type){
      case 'default':
        return "btn btn-default";
      break;

      case 'primary':
        return "btn btn-primary";
      break;

      case 'success':
        return "btn btn-success";
      break;

      case 'info':
        return "btn btn-info";
      break;

      case 'danger':
        return "btn btn-danger";
      break;

      case 'warning':
        return "btn btn-warning";
      break;
    }
  }
});


var ModalComponent = React.createClass({
    getInitialState: function() {
      return {};
    },

    getDefaultProps: function () {
      return {
        id: "idMo_default",
        valBtnClose: "Cerrar",
        valBtnAccion: "Accion"
      };
    },

    render : function(){
        return React.DOM.div({
          className: "modal fade",
          id: this.props.id,
          tabIndex: "-1",
          role: "dialog",
          children:[
            React.DOM.div({
              className: "modal-dialog",
              children: [
                React.DOM.div({
                  className: "modal-header",
                  children: [
                    React.DOM.button({
                      className: "close",
                      'data-dismiss': "modal",
                      type: "button"
                    }),
                    React.DOM.h4({
                      className: "modal-title",
                      children: this.props.titulo
                    })
                  ]
                }),

                React.DOM.div({
                  className: "modal-body",
                  children:[
                    this.props.contenido
                  ]
                }),

                React.DOM.div({
                  className: "modal-footer",
                  children:[
                    React.DOM.button({
                      className: "btn btn-default",
                      type: "button",
                      'data-dismiss': "modal",
                      children: this.props.valBtnClose
                    }),

                    React.DOM.button({
                      className: "btn btn-primary",
                      type: "button",
                      children: this.props.valBtnAccion
                    })
                  ]
                })
              ]
            })
          ]
        })
    }
});

ReactDOM.render(<ButtonComponent id="btn-modal" tipo="success" />, document.getElementById('btn'));
ReactDOM.render(<ModalComponent id="modal-prueba" titulo="ejemplo"/>, document.getElementById('contenedor-modal'));
